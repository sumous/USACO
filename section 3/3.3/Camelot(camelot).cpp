/*ID:maosong1
LANG:C++
PROB:camelot
*/
/**
* 写了一天了，还是一个个bug
* 一些bug真的感觉无心修改了，所以就把它排除在外了
* 感觉这个是自己写的最差的一个程序，好几个地方都是
* 至于优化方面：
* 第一：计算king和knight到其他所有点的最短路
*   刚开始我计算的是所有点对之间的最短路，显然超时的
* 第二：带king的knight只可能是在king坐标 +-2范围内的点带，
*   超过这范围，肯定是不可以的，因为king走得慢。
**/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#define EXECUTE 1
#define INF 2139062143
using namespace std;
int d[30][35][30][35], ans = INF;
int r, c, knight[850][2], n = 0, king[2];
int lx = INF, ly = INF, rx = 0, ry = 0;
/* knight走的方向 */
const int tx[] = {1,2,-1,1,-2,2,-1,-2};
const int ty[] = {2,1,2,-2,1,-1,-2,-1};


/* 找到枚举的边界，可以进行小部分优化 */
void find_range(int x, int y)
{
    if(lx > x) lx = x;
    if(rx < x) rx = x;
    if(ly > y) ly = y;
    if(ry < y) ry = y;
}
/* 输入数据 */
void load()
{
    fstream fin;
    fin.open("camelot.in", ios::in);

    fin>>r>>c;
    char ch;
    fin>>ch>>king[1];
    king[0] = ch-'A'+1;
    find_range(king[0], king[1]);

    while( fin>>ch )
    {
        knight[n][0] = ch-'A'+1;
        fin>>knight[n][1];
        find_range( knight[n][0], knight[n][1] );
        n++;
    }
    fin.close();
}
bool is_over(int x, int y)
{
    if(x>c || x<1 || y>r || y<1) return true;
    else return false;
}
/* 用宽搜找出(sx, sy)到其他点的最短步数 */
void bfs(int sx, int sy)
{
    d[sx][sy][sx][sy] = 0;
    bool vis[30][35] = {false};
    int q[900][3], front, rear;
    front = rear = 0;
    q[front][0] = sx, q[front][1] = sy;
    q[front][2] = 0;//步数
    vis[sx][sy] = true;

    while(front<=rear)
    {
        int cx = q[front][0], cy = q[front][1];
        int step = q[front][2];
        front++;

        for(int i = 0;i < 8;i++)
        {
            int nx = cx + tx[i], ny = cy + ty[i];
            if(!vis[nx][ny] && !is_over(nx, ny))
            {
                if(d[sx][sy][nx][ny] == INF)
                {//cout<<sx<<'\t'<<sy<<'\t'<<nx<<'\t'<<ny<<'\t'<<step+1<<endl;
                    d[nx][ny][sx][sy] = d[sx][sy][nx][ny] = step+1;
                }

                vis[nx][ny] = true;
                rear++;
                q[rear][0] = nx, q[rear][1] = ny;
                q[rear][2] = step + 1;
            }
        }
    }
}
/* 计算每两个点走“日”需要的步数 */
void cal()
{
    memset(d, 127, sizeof(d));
    bfs(king[0], king[1]);
    for(int i = 0;i < n;i++)
        bfs(knight[i][0], knight[i][1]);

}
int abs(int a)
{return a>0?a:-a;}

/* 枚举每个knight带king和不带king的情况 */
void is_min(int x, int y)
{
    int sum = 0;
    /* 计算（x,y）到每个点的步数和 */
    for (int i = 0;i < n;i++)
    {
        int tmp = d[x][y][ knight[i][0] ][ knight[i][1] ];
        if(tmp == INF) return;//（x,y）有不可达的knight,不满足
        sum += tmp;
    }
    if(sum > ans) return;
    /* 不带king的情况 */
    int m = max( abs(king[0]-x), abs(king[1]-y) ) + sum;
    if(ans>m) ans = m;

    /* 带king的情况 */
    for (int i = 0;i < n;i++)
    {
        int xyi = d[x][y][ knight[i][0] ][ knight[i][1] ];

        m = sum - xyi;
        if(m > ans) return;

        for (int j = king[0]-2;j <= king[0]+2;j++)
        {
            if(j < 1 || j > c) continue;
            for (int k = king[1]-2;k <= king[1]+2;k++)
            {
                if(k < 1 || k > r) continue;
                int jki = d[j][k][ knight[i][0] ][ knight[i][1] ];
                int jkxy = d[j][k][x][y];
                if(jki==INF || jkxy==INF) continue;//不可达

                int tmp = m + max( abs(king[0]-j), abs(king[1]-k) ) + jki + jkxy;
                if(ans>tmp) ans = tmp;

            }

        }
    }
}
/* 枚举每个点作为汇合点 */
void sol()
{
    if(n==1 && d[ king[0] ][ king[1] ][ knight[0][0] ][ knight[0][1] ] == INF)
    {
        ans = max( abs(king[0]-knight[0][0]), abs(king[1]-knight[0][1]) );
        return;
    }
    for (int i = lx;i < rx;i++)
        for (int j = ly;j <= ry;j++)
            is_min(i, j);
}
void out()
{
    #if EXECUTE == 1
        fstream fout;
        fout.open("camelot.out", ios::out);
        if(ans == INF) ans = 0;
        fout<<ans<<endl;
        fout.close();
    #else
        cout<<ans<<endl;
    #endif
}
int main()
{
    load();
    cal();
    sol();
    out();
    return 0;
}

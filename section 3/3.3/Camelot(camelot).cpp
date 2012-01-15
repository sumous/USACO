/*ID:maosong1
LANG:C++
PROB:camelot
*/
/**
* д��һ���ˣ�����һ����bug
* һЩbug��ĸо������޸��ˣ����ԾͰ����ų�������
* �о�������Լ�д������һ�����򣬺ü����ط�����
* �����Ż����棺
* ��һ������king��knight���������е�����·
*   �տ�ʼ�Ҽ���������е��֮������·����Ȼ��ʱ��
* �ڶ�����king��knightֻ��������king���� +-2��Χ�ڵĵ����
*   �����ⷶΧ���϶��ǲ����Եģ���Ϊking�ߵ�����
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
/* knight�ߵķ��� */
const int tx[] = {1,2,-1,1,-2,2,-1,-2};
const int ty[] = {2,1,2,-2,1,-1,-2,-1};


/* �ҵ�ö�ٵı߽磬���Խ���С�����Ż� */
void find_range(int x, int y)
{
    if(lx > x) lx = x;
    if(rx < x) rx = x;
    if(ly > y) ly = y;
    if(ry < y) ry = y;
}
/* �������� */
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
/* �ÿ����ҳ�(sx, sy)�����������̲��� */
void bfs(int sx, int sy)
{
    d[sx][sy][sx][sy] = 0;
    bool vis[30][35] = {false};
    int q[900][3], front, rear;
    front = rear = 0;
    q[front][0] = sx, q[front][1] = sy;
    q[front][2] = 0;//����
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
/* ����ÿ�������ߡ��ա���Ҫ�Ĳ��� */
void cal()
{
    memset(d, 127, sizeof(d));
    bfs(king[0], king[1]);
    for(int i = 0;i < n;i++)
        bfs(knight[i][0], knight[i][1]);

}
int abs(int a)
{return a>0?a:-a;}

/* ö��ÿ��knight��king�Ͳ���king����� */
void is_min(int x, int y)
{
    int sum = 0;
    /* ���㣨x,y����ÿ����Ĳ����� */
    for (int i = 0;i < n;i++)
    {
        int tmp = d[x][y][ knight[i][0] ][ knight[i][1] ];
        if(tmp == INF) return;//��x,y���в��ɴ��knight,������
        sum += tmp;
    }
    if(sum > ans) return;
    /* ����king����� */
    int m = max( abs(king[0]-x), abs(king[1]-y) ) + sum;
    if(ans>m) ans = m;

    /* ��king����� */
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
                if(jki==INF || jkxy==INF) continue;//���ɴ�

                int tmp = m + max( abs(king[0]-j), abs(king[1]-k) ) + jki + jkxy;
                if(ans>tmp) ans = tmp;

            }

        }
    }
}
/* ö��ÿ������Ϊ��ϵ� */
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

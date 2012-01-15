/*ID:maosong1
LANG:C++
PROB:range
*/
/**
* 动态规划
* 状态：d[x][y]:(x, y)点为正方形左上顶点，所能组成的
* 最大的正方形
* 方程：d[x][y] = min(d[x+1][y], d[x][y+1], d[x+1][y+1]) + 1
* 然后，枚举每个点(i, j)作为正方形左上顶点时，相应正方形数sn[n]+1(n=2..d[i][j])
**/
#include <iostream>
#include <fstream>
#define EXE 1
using namespace std;
int d[252][252] = {0}, n, map[252][252], sn[252] = {0};
bool vis[252][252] = {false};
/* 输入数据 */
void load()
{
    fstream fin;
    fin.open("range.in", ios::in);
    fin>>n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char ch;
            fin>>ch;
            map[i][j] = ch - '0';

        }

    fin.close();
}
/* 判断是否越界 */
bool is_over(int x, int y)
{
    if ( (x<1) || (x>n) || (y<1) || (y>n) ) return true;
    else return false;
}
/* 判断(x+1,y)(x,y+1)(x+1,y+1)是否越界 */
bool three_over(int x, int y)
{
    if (is_over(x+1, y) || is_over(x, y+1) || is_over(x+1, y+1))
        return true;
    else return false;
}

/* 找出三个数的最小值 */
int min_three(int a, int b, int c)
{
    return min( min(a, b), c );
}
/* 用动态规划处理数据 */
void dp()
{
    for (int i = n; i > 0; i--)
        for (int j = n; j > 0; j--)
        {
            if(map[i][j])
            {
                if(!three_over(i, j))
                {//cout<<i<<" "<<j<<endl;
                    d[i][j] = min_three(d[i+1][j], d[i][j+1], d[i+1][j+1]) + 1;
                }
                else d[i][j] = 1;
            }
            else d[i][j] = 0;
        }
}
/* 根据d[][]，计算sn[] */
void work()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int size = d[i][j];
            for (int k = 2; k <= size; k++)
                sn[k]++;
        }
    }
}
/* 输出 */
void out()
{
    #if EXE == 1
        fstream fout;
        fout.open("range.out", ios::out);
        for (int i = 2; i <= n; i++)
            if (sn[i]) fout<<i<<" "<<sn[i]<<endl;
    #else
        for (int i = 2; i <= n; i++)
            if (sn[i]) cout<<i<<" "<<sn[i]<<endl;
    #endif
}
int main()
{
    load();
    dp();
    work();
    out();
    return 0;
}

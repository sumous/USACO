/*ID:maosong1
LANG:C++
PROB:game1
*/
/**
* 太猥琐的一道题了。完全没感觉，竟然会是动态规划。
* 博弈问题。
* 博弈中除了每次取自己利益最大，其实也可以让对方
* 利益最小。
* sum[i][j]:从i到j所有数的和
* d[i][j]:当前状态下，取的人能得到的最大效益
* d[i][j] = sum[i][j] - min( d[i][j-1], d[i+1][j] )
* (i = n...1, j = i+1...n)
**/
#include <iostream>
#include <fstream>
#define EXE 1
using namespace std;
int sum[252][252] = {0}, d[252][252] = {0}, n;
int s[252];
void load()
{
    fstream fin;
    fin.open("game1.in", ios::in);
    fin>>n;
    /* 输入序列 */
    for (int i = 1; i <= n; i++) fin>>s[i];
    fin.close();
}
/* 用动态规划计算d[i][j] */
void dp()
{
    /* 计算sum[i][j] */
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum[i][j] = sum[i][j-1] + s[j];
        }
    }
    /* 计算d[i][j] */
    for (int i = 1; i <= n; i++) d[i][i] = s[i];
    for (int i = n; i > 0; i--)
        for (int j = i+1;j <= n; j++)
        {
            //if(i == j) continue;
            d[i][j] = sum[i][j] - min(d[i][j-1], d[i+1][j]);
        }
}
void out()
{
    #if EXE == 1
        fstream fout;
        fout.open("game1.out", ios::out);
        fout<<d[1][n]<<" "<<sum[1][n]-d[1][n]<<endl;
        fout.close();
    #else
        cout<<d[1][n]<<" "<<sum[1][n]-d[1][n]<<endl;
    #endif
}
int main()
{
    load();
    dp();
    out();
    return 0;
}

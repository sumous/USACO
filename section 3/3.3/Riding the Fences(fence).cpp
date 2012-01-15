/*ID:maosong1
LANG:C++
PROB:fence
*/
/***************************************************************
欧拉路的经典算法，用深搜，用euler后记录，这样错了的话，
程序会自动调整到其他路线。
***************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int d[501][501];
int euler[1025], F, m = 0;

int find_start()
{
    int i = 1;
    while(i<=500)
    {
        if(d[i][0]%2) return i;
        i++;
    }
    return 1;
}
void load()
{
    memset(d, 0, sizeof(d));
    cin>>F;
    for(int i = 0;i < F;i ++)
    {
        int a, b;
        cin>>a>>b;
        d[a][0] ++,d[b][0]++;
        d[a][b]++, d[b][a]++;
    }
}
void print()
{
    for(int i = m-1;i >= 0;i --) cout<<euler[i]<<endl;
}
void dfs(int s)
{
    for(int i = 1;i <= 500;i ++)
    {
        if(d[s][i] > 0)
        {
            d[s][i]--,d[i][s]--;
            dfs(i);
        }
    }
    euler[m++] = s;
}
int main()
{
    freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	load();
	int s = find_start();
	dfs(s);
	print();
    return 0;
}

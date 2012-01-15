/*ID:maosong1
LANG:C++
PROB:butter
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#define INF 2139062143
using namespace std;

int N, P, C, cow[801], d[801][801];
void load()
{
    cin>>N>>P>>C;
    for(int i = 0;i < N;i ++) cin>>cow[i];
    memset(d, 127, sizeof(d));
    for(int i = 0;i < C;i ++)
    {
        int a, b, w;
        cin>>a>>b>>w;
        d[a][b] = d[b][a] = w;
    }//cout<<d[0][0]<<endl;
    for(int i = 0;i <= P;i ++) d[i][i] = 0;
}
void floyd()
{
    for(int k = 1;k <= P;k ++)
        for(int i = 1;i <= P;i ++)
            for(int j = 1;j <= P;j ++)
            {
                if(d[i][k]!=INF && d[k][j]!=INF && d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
}
void find_min()
{
    int min = INF;
    for(int i = 1;i <= P;i ++)
    {
        int dis = 0;
        for(int j = 0;j < N;j ++)
            dis += d[i][cow[j]];
        if(dis<min) min = dis;
    //    cout<<dis<<endl;
    }
    cout<<min<<endl;
}
int main()
{
    freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	load();
	floyd();
	find_min();
    return 0;
}

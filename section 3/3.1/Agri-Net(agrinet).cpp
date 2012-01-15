/*ID:maosong1
LANG:C++
PROB:agrinet
*/
/**
* 最小生成树，用prim算法即可
*一开始我把这题写着就写到最短路去了，杯具啊。
*关于prim算法的介绍，我转了篇比较清晰的
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
long map[101][101],n;

long prim()
{
	bool vis[101];
	int i,j,pos = 0;
	long low[101],res = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for(i = 1;i < n;i ++) low[i] = map[pos][i];
	for(i = 1;i < n;i ++)
	{
		long min = 100000;
		for(j = 0;j < n;j ++)
			if(!vis[j] && min>low[j]){min = low[j];pos = j;}
		vis[pos] = true;
		res += min;
		for(j = 0;j < n;j ++)
			if(!vis[j] && low[j]>map[pos][j]) low[j] = map[pos][j];
	}
	return res;
}
int main()
{
	freopen("agrinet.in","r",stdin);
//	freopen("agrinet.out","w",stdout);

	cin>>n;
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++) cin>>map[i][j];

	cout<<prim()<<endl;
	return 0;
}

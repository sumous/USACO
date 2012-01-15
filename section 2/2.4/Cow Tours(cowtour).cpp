/*ID:maosong1
LANG:C++
PROB:cowtour
*/
/**
*注意的一点：不只两个牧场，题目是说选两个牧场，加一条路上去（害死不少人啊） 
*先用floyd算法，计算出每两点之间的最短距离 map 
*然后，统计出每个点距任意可连通（直接或间接）点的最长距离dis 
*枚举每两个不连通的点i,j，找出最小的dist[i,j]+dis[i]+dis[j] ，保存为ans 
* 将ans和每个点的dis值比较。也就是说，可以连通其他牧场，而如果该牧场的直径比
*那两个连通的牧场直径还大，那么，整个牧场的直径就是改牧场直径 
*Accepted 
**/ 
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define inf 1e20
using namespace std;
int n,grid[151][2];
double map[151][151];

double dis[151];
double dist(int i,int j)
{
	int a=grid[i][0]-grid[j][0],b=grid[i][1]-grid[j][1];
	return sqrt(a*a+b*b);
}

void floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(map[i][j]>map[i][k]+map[k][j]) map[i][j]=map[i][k]+map[k][j];

}
int main()
{

	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	cin>>n;
	memset(dis,0,sizeof(dis));
	for(int i=0;i<n;i++) cin>>grid[i][0]>>grid[i][1];
	getchar();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='1') map[i][j]=dist(i,j);
			else map[i][j]=inf;
			if(i==j) map[i][j]=0;
		}
		getchar();
	}


	floyd();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
				if((map[i][j]!=inf)&&(map[i][j]>dis[i]))  dis[i]=map[i][j];
		}
	double ans=inf;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(map[i][j]==inf)
			{
				double len=dist(i,j)+dis[i]+dis[j];
				if(len<ans) ans=len;
	
			}
		}
	for(int i=0;i<n;i++) if(dis[i]>ans) ans=dis[i];//这步就是体现出了不只两个牧场 
	printf("%.6lf\n",ans);
	return 0;
}
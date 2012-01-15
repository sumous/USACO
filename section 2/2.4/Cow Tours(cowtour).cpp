/*ID:maosong1
LANG:C++
PROB:cowtour
*/
/**
*ע���һ�㣺��ֻ������������Ŀ��˵ѡ������������һ��·��ȥ�����������˰��� 
*����floyd�㷨�������ÿ����֮�����̾��� map 
*Ȼ��ͳ�Ƴ�ÿ������������ͨ��ֱ�ӻ��ӣ���������dis 
*ö��ÿ��������ͨ�ĵ�i,j���ҳ���С��dist[i,j]+dis[i]+dis[j] ������Ϊans 
* ��ans��ÿ�����disֵ�Ƚϡ�Ҳ����˵��������ͨ�����������������������ֱ����
*��������ͨ������ֱ��������ô������������ֱ�����Ǹ�����ֱ�� 
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
	for(int i=0;i<n;i++) if(dis[i]>ans) ans=dis[i];//�ⲽ�������ֳ��˲�ֻ�������� 
	printf("%.6lf\n",ans);
	return 0;
}
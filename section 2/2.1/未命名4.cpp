#include<iostream>
#include<fstream>
using namespace std;
int n,v[26],m,g[16][26],now[26],res[16],dat[16],minn=2147483647;
void dfs(int deep,int count)
{
	if(deep==m+1)
	{
		for(int i = 1;i<=n;i++)
			if(now[i]<v[i]) return;
		if(count<minn)
		{
			minn=count;
			for(int i = 1;i<=minn;i++) res[i]=dat[i];
		}
		return;
	}
	for(int i = 1;i<=n;i++) now[i]+=g[deep][i];
	dfs(deep+1,count+1);
	for(int i = 1;i<=n;i++) now[i]+=g[deep][i];
	dfs(deep+1,count);
}
dfs(1,0)
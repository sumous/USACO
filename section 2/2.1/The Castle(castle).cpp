/*ID:maosong1
LANG:C++
PROB:castle
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int map[51][51],room[2500],val[51][51];
int row,col,rsum=0;
bool vis[51][51];
int dfs(int r,int c)
{
	int sum=1;
	vis[r][c]=true;
	val[r][c]=rsum;//cout<<r<<" "<<c<<endl;
	if((map[r][c]&1)==0 && !vis[r][c-1]) sum+=dfs(r,c-1);
	if((map[r][c]&2)==0 && !vis[r-1][c]) sum+=dfs(r-1,c);
	if((map[r][c]&4)==0 && !vis[r][c+1]) sum+=dfs(r,c+1);
	if((map[r][c]&8)==0 && !vis[r+1][c]) sum+=dfs(r+1,c);
	return sum;
}
int is_vis()//判断是否完全访问完 
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			if(!vis[i][j]) return i*col+j;
	return -1;
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout); 
	cin>>col>>row;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>map[i][j];
	memset(vis,false,sizeof(vis));
	int pla=0,max=0;
	while(pla>=0)//直到所有的被访问完 
	{
		room[rsum]=dfs(pla/col,pla%col);
		if(room[rsum]>max) max=room[rsum];
		rsum++;
		pla=is_vis();
	}
	cout<<rsum<<endl<<max<<endl; 

	int mc,mr;
	char dir;
	max=0;
	for(int i=0;i<col;i++)
		for(int j=row-1;j>=0;j--)
		{
			if(j>0 && val[j][i]!=val[j-1][i])
			{
				int tmp=room[val[j][i]]+room[val[j-1][i]];
				if(tmp>max){max=tmp;mr=j;mc=i;dir='N';}
			}
			if(i<col-1 && val[j][i]!=val[j][i+1])
			{
				int tmp=room[val[j][i]]+room[val[j][i+1]];
				if(tmp>max){max=tmp;mr=j;mc=i;dir='E';}
			}
		}
	cout<<max<<endl<<mr+1<<" "<<mc+1<<" "<<dir<<endl;
	return 0;
}
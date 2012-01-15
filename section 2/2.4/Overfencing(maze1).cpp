/*ID:maosong1
LANG:C++
PROB:maze1
*/
/**
*比较简单的题，但是做了很久。太久没写搜索的了。
*一开始没理解题目的意思就拍代码了
*只要理解这就简单了：把两个出口分别作为起点，
*分别将整个地图走两遍，此时求出两次每个点到两个
*出口的最短距离中短的一个，再找出最短距离最长的一个点。 
*Accepted
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int ext[2][2],w,h;
char map[205][80];
int move[2][105][40],cur;

bool is_ok(int x,int y)
{
	return (x>0 && x<2*h && y>0 && y<2*w);
}
void dfs(int step,int x,int y)
{
	if(step<move[cur][x/2][y/2]) move[cur][x/2][y/2]=step;
	else return;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(is_ok(nx+dx[i],ny+dy[i])  && map[nx][ny]==' ')
		{
			nx+=dx[i];ny+=dy[i];
			dfs(step+1,nx,ny);
		}
	}
}
int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	memset(move,127,sizeof(move));
	cin>>w>>h;
	int j=0;
	getchar();
	for(int i=0;i<2*h+1;i++) gets(map[i]);
	for(int i=0;i<2*w+1;i++) 
	{
		if(j==2) break;
		if(map[0][i]==' '){ext[j][0]=1;ext[j++][1]=i;}
		if(map[2*h][i]==' '){ext[j][0]=2*h-1;ext[j++][1]=i;}
	}
	for(int i=1;i<2*h;i++)
	{
		if(j==2) break;
		if(map[i][0]==' '){ext[j][0]=i;ext[j++][1]=1;}
		if(map[i][2*w]==' '){ext[j][0]=i;ext[j++][1]=2*w-1;}
	}
	cur=0;
	dfs(1,ext[0][0],ext[0][1]);
	cur=1;
	dfs(1,ext[1][0],ext[1][1]);
	int ans=0;
	for(int i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{//cout<<move[1][i][j]<<" ";
			if(move[1][i][j]>=move[0][i][j] && move[0][i][j]>ans) ans=move[0][i][j];
			if(move[0][i][j]>move[1][i][j] && move[1][i][j]>ans) ans=move[1][i][j];
		}
	//	cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
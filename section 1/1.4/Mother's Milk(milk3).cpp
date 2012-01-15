/*ID:maosong1
LANG:C++
PROB:milk3
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int A,B,C;
int res[22], len=0;
bool vis[22][22][22]={false};
bool is_ok(int t)
{
	for(int i = 0;i < len;i++)
		if(res[i]==t) return false;
	return true;
}
void dfs(int a, int b, int c)
{
	if(a==0 && is_ok(c)) res[len++] = c;
	/**
	* a->c
	*/
 	if(a>=C-c && !vis[a+c-C][b][C])	{vis[a+c-C][b][C]=true;dfs(a+c-C,b,C);}
 	if(a<C-c && !vis[0][b][c+a]){vis[0][b][c+a]=true;dfs(0,b,c+a);}
 	
 	/**
	* a->b
	*/
 	if(a>=B-b && !vis[a+b-B][B][c])	{vis[a+b-B][B][c]=true;dfs(a+b-B,B,c);}
 	if(a<B-b && !vis[0][b+a][c]){vis[0][b+a][c]=true;dfs(0,b+a,c);}
 	/**
	* b->c
	*/
 	if(b>=C-c && !vis[a][b+c-C][C])	{vis[a][b+c-C][C]=true;dfs(a,b+c-C,C);}
 	if(b<C-c && !vis[a][0][c+b]){vis[a][0][c+b]=true;dfs(a,0,c+b);}
 	
 	/**
	* b->a
	*/
 	if(b>=A-a && !vis[a][b+a-A][c])	{vis[a][b+a-A][c]=true;dfs(A,b+a-A,c);}
 	if(b<A-a && !vis[a+b][0][c]){vis[a+b][0][c]=true;dfs(a+b,0,c);}
 	/**
	* c->a
	*/
 	if(c>=A-a && !vis[A][b][c+a-A])	{vis[A][b][c+a-A]=true;dfs(A,b,c+a-A);}
 	if(c<A-a && !vis[a+c][b][0]){vis[a+c][b][0]=true;dfs(a+c,b,0);}
 	
 	/**
	* c->b
	*/
 	if(c>=B-b && !vis[a][B][c+b-B])	{vis[a][B][c+b-B]=true;dfs(a,B,c+b-B);}
 	if(c<B-b && !vis[a][b+c][0]){vis[a][b+c][0]=true;dfs(a,b+c,0);}
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&A ,&B, &C);
	dfs(0,0,C);
	sort(res,res+len);
	for(int i = 0;i < len-1;i ++) printf("%d ",res[i]);
	printf("%d\n", res[len-1]);
	return 0;
}
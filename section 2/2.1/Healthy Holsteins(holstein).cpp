/*ID:maosong1
LANG:C
PROB:holstein
*/
#include<stdio.h>
#include<string.h>
int v[26],g[16][26];
int res[26],len,V,G,sum[26],dat[26];
int minn=2147483647;
void dfs(int deep,int count)
{
	int i;
	if(deep==G)
	{
		for(i=0;i<V;i++)
			if(sum[i]<v[i]) return;	
		if(minn>count)
		{
			minn=count;
			for(i=1;i<=minn;i++) res[i]=dat[i];
		}
		return;
	}
	dat[count+1]=deep;
	for(i=0;i<V;i++) sum[i]+=g[deep][i];	
	dfs(deep+1,count+1);
	for(i=0;i<V;i++) sum[i]-=g[deep][i];
	dfs(deep+1,count);
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	int i,j;
	scanf("%d",&V);
	for(i=0;i<V;i++) scanf("%d",&v[i]);
	scanf("%d",&G);
	for(i=0;i<G;i++)
		for(j=0;j<V;j++) scanf("%d",&g[i][j]);
		
	memset(sum,0,sizeof(sum));
	dfs(0,0);
	printf("%d",minn);
	for(i=1;i<=minn;i++) printf(" %d",res[i]+1);
	putchar('\n');
	return 0;
}
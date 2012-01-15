/*ID:maosong1
LANG:C
PROB:numtri
*/
#include<stdio.h>
#include<string.h>
int n;
int tri[1005][1005];
int d[1005][1005];
int max(int a,int b)
{
	return a>b?a:b;
}
int dp(int row,int col)
{
	if(row==n) return 0;
	if(d[row][col]!=-1) return d[row][col];
	d[row][col]=0;
	d[row][col]+=max(dp(row+1,col),dp(row+1,col+1))+tri[row][col];
	return d[row][col];
}
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int i,j;
	memset(d,-1,sizeof(d));
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<i+1;j++) scanf("%d",&tri[i][j]);
	printf("%d\n",dp(0,0));
	return 0;
}
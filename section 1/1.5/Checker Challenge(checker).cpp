/*ID:maosong1
LANG:C
PROB:checker
*/
#include<stdio.h>
int n,ans,aim;
int a[25];
void dfs(int row, int ld,int rd,int i)
{
	if(row!=aim)
	{
		int pos=aim&(~(row|ld|rd));
		while(pos!=0)
		{
			int p=pos&(-pos);
			pos-=p;
			if(ans<3)
			{
				int l=1,k=p;
				while(k!=1)
				{//printf("test");
					k>>=1;
					l++;
				}
				a[i]=l;
			}
			dfs(row|p,(ld|p)<<1,(rd|p)>>1,i+1);
		}
	}
	else
	{
		ans++;
		if(ans<=3)
		{
			int j;
			printf("%d",a[1]);
			for(j = 2;j<=n;j++) printf(" %d",a[j]);
			putchar('\n');
		}
	}
}
int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	scanf("%d",&n);
	aim=(1<<n)-1;
	dfs(0,0,0,1);
	printf("%d\n",ans);
	return 0;
}
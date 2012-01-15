/*ID:maosong1
LANG:C
PROB:hamming
*/
#include<stdio.h>
int res[65],N,B,D;
int len;
int is_fit(int t)
{
	int count=0;
	while(t)
	{
		t=t&(t-1);
		count++;
	}
	if(count<D) return 0;
	else return 1;
}
int main()
{	
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	int i,j;
	int flag;
	scanf("%d %d %d",&N,&B,&D);
	
	res[len++]=0;
	for(i=1;i<(1<<B);i++)
	{
		flag=1;
		for(j=0;j<len;j++)
		{
			int tmp=i^res[j];
			if(!is_fit(tmp)){flag=0;break;}
		}
		if(flag) res[len++]=i;
		if(len==N) break;
	}
	i=0;
	while(i<len)
	{
		printf("%d",res[i++]);
		for(j=0;j<9&&i<len;j++) printf(" %d",res[i++]);
		putchar('\n');
	}
	return 0;
}
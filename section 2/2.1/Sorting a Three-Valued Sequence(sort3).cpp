/*ID:maosong1
LANG:C
PROB:sort3
*/
#include<stdio.h>
#define M 1005
int a[M];
int sum[3]={0};
int ext(int* a1,int* a2)
{
	int tmp=*a1;
	*a1=*a2;
	*a2=tmp;
}
int main()
{
	int n,i,j,count=0;
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]-1]++;
	}
	/*
	遇到2，从sum[0]搜索到n 
	遇到3，从n搜索到sum[0] 
	*/ 
	for(i=0;i<sum[0];i++)
	{
		if(a[i]==2)
			for(j=sum[0];j<n;j++)
				if(a[j]==1){ext(&a[i],&a[j]);count++;break;}

		if(a[i]==3)
			for(j=n-1;j>=sum[0];j--)
				if(a[j]==1){ext(&a[i],&a[j]);count++;break;}
	}
	/*
	从sum[0]+sum[1]搜索到n 
	*/
	j=sum[0]+sum[1];
	for(i=sum[0];i<sum[0]+sum[1];i++)
	{
		if(a[i]!=2)
			for(;j<n;j++)
			{
				if(a[j]==2){ext(&a[i],&a[j]);count++;}
			}
	}
	printf("%d\n",count);
//	printf("%d\n",sum[1]);
	
	return 0;
}
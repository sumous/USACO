/*ID:maosong1
LANG:C
PROB:dualpal
*/
#include<stdio.h>
int pal(int n,int t)                    //判断t在n进制下是否为回文数 
{
	int i,j=0,a[20],flag=1,k;
	while(t!=0)                        //把t的每个位提出放在数组中 
	{
		a[j]=t%n;printf("%d",a[j]);
		t/=n;
		j++;
	}
	i=0;
	for(k=j/2;k>=1;k--)             //判断a[20]是否为回文串 
		{
			if(a[j-k]!=a[k-1]) {flag=0;break;}
		}
	if(flag) return 1;
	else return 0;
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("dualpal.in","r");
	fout=fopen("dualpal.out","w");
	int flag,i,j,n,t=0,s;
	fscanf(fin,"%d%d",&n,&s);
	for(i=s+1;;i++)                     //从s+1开始，对每个进行枚举 
	{

		flag=0;printf("%d\n",i);
		for(j=2;j<11;j++)               //每个进制进行枚举 
		{
		    if(pal(j,i)) flag++;
			if(flag>=2) {fprintf(fout,"%d\n",i);t++;break;}//有两个进制满足的话就输出并跳出 
		
		}

		if(t==n) break;
		
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
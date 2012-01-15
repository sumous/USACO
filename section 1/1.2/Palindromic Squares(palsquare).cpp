/*ID:maosong1
LANG:C
PROB:palsquare
*/
#include<stdio.h>
#include<string.h>
char dic[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
//dic[]用于检索 

int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	long i,j,k,q,p;
	int n,a[20],flag;
    int sqr[20];                              
	scanf("%d",&n);
	for(i=1;i<=300;i++)
	{
		flag=1;
			//接下来把i的平方转换放在a[10] 
		k=i*i;
		p=0;
		while(k!=0)
		{
			sqr[p]=k%n;
			k/=n;p++;		
		}
    	for(k=p/2;k>=1;k--)          //判断是否为回文字串 
		{
			if(sqr[p-k]!=sqr[k-1]) {flag=0;}
		}
		 //接下来把i转换放在sq[10] 
		j=i;                           
		q=0;
		while(j!=0)
		{
			a[q]=j%n;
			j/=n;q++;		
		}

	
		if(flag==1) 
		{
			for(j=q-1;j>=0;j--) printf("%c",dic[a[j]]);
			printf(" ");
			for(j=0;j<p;j++) printf("%c",dic[sqr[j]]);
			printf("\n");
		}
	}

	return 0;
}
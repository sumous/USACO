/*ID:maosong1
LANG:C
PROB:dualpal
*/
#include<stdio.h>
int pal(int n,int t)                    //�ж�t��n�������Ƿ�Ϊ������ 
{
	int i,j=0,a[20],flag=1,k;
	while(t!=0)                        //��t��ÿ��λ������������� 
	{
		a[j]=t%n;printf("%d",a[j]);
		t/=n;
		j++;
	}
	i=0;
	for(k=j/2;k>=1;k--)             //�ж�a[20]�Ƿ�Ϊ���Ĵ� 
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
	for(i=s+1;;i++)                     //��s+1��ʼ����ÿ������ö�� 
	{

		flag=0;printf("%d\n",i);
		for(j=2;j<11;j++)               //ÿ�����ƽ���ö�� 
		{
		    if(pal(j,i)) flag++;
			if(flag>=2) {fprintf(fout,"%d\n",i);t++;break;}//��������������Ļ������������ 
		
		}

		if(t==n) break;
		
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
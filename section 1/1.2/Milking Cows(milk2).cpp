/*ID:maosong1
LANG:C
PROB:milk2
*/
#include<stdio.h>
#include<string.h>
 struct Milk
{
	int start;
	int end;
};
int main()
{
	FILE* fin=fopen("milk2.in","r");
	FILE* fout=fopen("milk2.out","w");
	int n,i,j,tmax,nmax,nomax;
   struct Milk temp; 
	struct Milk a[5001];
	struct Milk cur;
	fscanf(fin,"%d",&n);//测试组数 
	for(i=0;i<n;i++)//输入每组的起始与结束时间 
	{
		fscanf(fin,"%d%d",&a[i].start,&a[i].end);
	}
for(i=0;i<n;i++)//按起始时间进行排序 
{
	for(j=i;j<n;j++)
	{
		if(a[i].start>a[j].start)
		{
			temp=a[i];a[i]=a[j];a[j]=temp;
		}
	}
//printf("%d ",a[i].start);
}
	cur=a[0];
   nmax=0;//有农夫在挤奶的时间段 
   nomax=0;//无农夫在挤奶是时间段 
	for(i=1;i<n;i++)
	{
		if(cur.end<a[i].start)
		{
			tmax=a[i].start-cur.end;
			if(tmax>nomax) nomax=tmax;
			
			tmax=cur.end-cur.start;
			if(tmax>nmax) nmax=tmax;
			cur=a[i];
		}
		else
		{
		if(cur.end<a[i].end)
			 cur.end=a[i].end;
		}
		
	}

    tmax =cur.end-cur.start;
    if(tmax> nmax) nmax=tmax;
 
	fprintf(fout,"%d %d\n",nmax,nomax);
	return 0;
}
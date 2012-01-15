/*ID: maosong1
LANG: C
PROB: friday
*/
#include<stdio.h>
int is_leap(int year)
{
	int flag=0;
	if(((year%4==0)&&(year%100!=0))||(year%400==0)) flag=1;
	return flag;
}
main()
{
	FILE *fin=fopen("friday.in","r");
	FILE *fout=fopen("friday.out","w");
	int n,i,sum=1,year=1900,a[7]={0},flag,temp;
	int day[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	fscanf(fin,"%d",&n);
	for(;year<1900+n;year++)
	{
		flag=is_leap(year);
//printf("%d",flag);
		for(i=0;i<12;i++)
		{
			temp=(sum+13)%7;
			a[temp]++; 
			sum+=day[flag][i];
		}
	}
	for(i=0;i<6;i++)
	{
		fprintf(fout,"%d ",a[i]);
	}
	fprintf(fout,"%d",a[6]);
	fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
}
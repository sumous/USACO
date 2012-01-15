/*ID: maosong1
LANG: C
PROB: beads
*/
#include<stdio.h>
#include<string.h>
main()
{
	FILE *fin=fopen("beads.in","r");
	FILE *fout=fopen("beads.out","w");
	 char a[1053],ch,b[351];
	 int sum,n,max=0,i,j,k;
	fscanf(fin,"%d%s",&n,b);
	strcpy(a,b);
	strcat(a,b);
	strcat(a,b);
	for(i=n;i<2*n;i++)
	{
	    sum=0;
		j=i;
		k=i+1;
		ch=a[j];
		while(ch=='w')
		{
			sum++;
			j--;
			ch=a[j];
		}
		while(a[j]==ch||a[j]=='w')
		{
          	j--;
			sum++;
		}
		ch=a[k];
			while(ch=='w')
		{
			sum++;
			k++;
			ch=a[k];
		}
	
		while(a[k]==ch||a[k]=='w')
		{	
			k++;	
			sum++;
		}
		max=(max>sum?max:sum);
		if(max>n) max=n;
	}
	fprintf(fout,"%d\n",max);
	fclose(fin);
	fclose(fout);
}
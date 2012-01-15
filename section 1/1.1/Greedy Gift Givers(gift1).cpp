/*ID: maosong1
LANG: C
PROB: gift1
*/
#include <stdio.h>
#include<string.h>
main () 
	{
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int n,i,j,k,a,b,t;
    fscanf (fin, "%d",&n);
    char name[10][14],ch[14];
    int money[10]={0};
    for(i=0;i<n;i++) fscanf(fin,"%s",name[i]);
    for(i=0;i<n;i++)
    {
    	j=0;
    	fscanf(fin,"%s",ch);
    	while(strcmp(name[j],ch)) j++;
    	fscanf(fin,"%d%d",&a,&b);
    	if(b==0) t=0;
    	else t=a/b;
    	money[j]-=(b*t);
    	for(k=0;k<b;k++)
    	{
    		j=0;
    		fscanf(fin,"%s",ch);
    		while(strcmp(name[j],ch)) j++;
    		money[j]+=t;
		}
	}
	for(i=0;i<n;i++)
    fprintf (fout, "%s %d\n",name[i],money[i]);
   fclose(fin);
   fclose(fout);
}

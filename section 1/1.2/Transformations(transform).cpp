/*ID:maosong1
LANG:C
PROB:transform
*/
#include<stdio.h>
//一下依次是1-6种情况 
int transform1(char a[][11],char b[][11],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=n-1,k=0;j>=0;j--,k++)
		{
		if(a[j][i]!=b[i][k]) return 0;
		}	
	}
	return 1;
}
int transform2(char a[][11],char b[][11],int n)
{
		int i,j,k,l;
	for(i=n-1,l=0;i>=0;i--,l++)
	{
		for(j=n-1,k=0;j>=0;j--,k++)
		{
		if(a[i][j]!=b[l][k]) return 0;
		}	
	}
	return 1;
}
int transform3(char a[][11],char b[][11],int n)
{
		int i,j,k,l;
	for(i=n-1,l=0;i>=0;i--,l++)
	{
		for(j=0,k=0;j<n&&k<n;j++,k++)
		{
		if(a[j][i]!=b[l][k]) return 0;
		}	
	}
	return 1;
}
int transform4(char a[][11],char b[][11],int n)
{
		int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=n-1,k=0;j>=0;j--,k++)
		{
		if(a[i][j]!=b[i][k]) return 0;
		}	
	}
	return 1;
}
int transform5(char a[][11],char b[][11],int n)
{
		int i,j,k,temp;
	for(i=0;i<n;i++)
	{
		for(j=n-1,k=0;k<j;j--,k++)
		{
	temp=a[i][k];a[i][k]=a[i][j];a[i][j]=temp;
		}	
	}
		if(transform1(a,b,n)||transform2(a,b,n)||transform3(a,b,n)) return 1;
		else return 0;
}
int transform6(char a[][11],char b[][11],int n)
{
		int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(a[i][j]!=b[i][j]) return 0;
		}	
	}
	return 1;
}
int main()
{
	FILE *fin=fopen("transform.in","r");
	FILE *fout=fopen("transform.out","w");
	int n,i,j,result;
	char a[11][11],b[11][11];
	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++) fscanf(fin,"%s",a[i]);
	for(i=0;i<n;i++) fscanf(fin,"%s",b[i]);

   switch(transform1(a,b,n)) 
   {
   case 1:fprintf(fout,"%d\n",1);break;
   case 0:switch(transform2(a,b,n))
          {
          	case 1:fprintf(fout,"%d\n",2);break;
          	case 0:switch(transform3(a,b,n))
          	       {
          	       	case 1:fprintf(fout,"%d\n",3);break;
          	       	case 0:switch(transform4(a,b,n))
          	       	       {
          	       	       	case 1:fprintf(fout,"%d\n",4);break;
          	       	       	case 0:switch(transform5(a,b,n))
          	       	       	       {
          	       	       	       	case 1:fprintf(fout,"%d\n",5);break;
          	       	       	       	case 0:switch(transform6(a,b,n))
          	       	       	       	       {
          	       	       	       	       	case 1:fprintf(fout,"%d\n",6);break;
          	       	       	       	       	case 0:fprintf(fout,"%d\n",7);break;
			                               }
								   }
		                   }
				   }
		  }
   }
 
//	fprintf(fout,"%d",j);
	fclose(fin);
	fclose(fout);
	return 0;
}

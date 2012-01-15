/*ID:maosong1
LANG:C
PROB:namenum
*/
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,flag=0,count=0,num[13],s[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
	char dic[13],name[13];
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
    i=-1;
	while(scanf("%c",&name[++i])!=-1&&name[i]!='\n')
	{
		num[i]=name[i]-'0';
		
	}
   if(name[i]='\n') num[i]=0;
   //printf("%d",i);
   	freopen("dict.txt","r",stdin);
	while(scanf("%s",dic)!=-1)
	{

		if(i!=strlen(dic)) continue;
		j=-1;//printf("%s\n",dic);
	while(dic[++j]!=0&&j<strlen(dic))
		{
		if(s[dic[j]-'A']!=num[j]) break;
		}
		if(j==i) {printf("%s\n",dic);count++;}
	}
	if(count==0) printf("NONE\n");
	return 0;
}
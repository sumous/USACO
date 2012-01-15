/*ID:maosong1
LANG:C++
PROB:preface
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
char dic[4][10][5]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},//¸ö
			  		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},//Ê®
     		  		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},//°Ù
         	  		{"","M","MM","MMM"}};//Ç§
char letter[]="IVXLCDM";
int sum[7]={0};
void cal(int t,int j)
{
	for(int k=0;k<strlen(dic[j][t%10]);k++)
	{
		char ch=dic[j][t%10][k];
		for(int l=0;l<7;l++)
		{
			if(letter[l]==ch){sum[l]++;break;}
		}
	}
}
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp=i,j=0;//cout<<"test";
		while(tmp/10!=0)
		{
			cal(tmp, j);
			tmp/=10;j++;
		}
		cal(tmp,j);
	}
	for(int i=0;i<7;i++)
		if(sum[i]) cout<<letter[i]<<" "<<sum[i]<<endl;
	return 0;
}
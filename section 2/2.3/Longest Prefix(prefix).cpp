/*ID:maosong1
LANG:C++
PROB:prefix
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#define M 200005
using namespace std;
char pri[205][11],s[M];
int len[205],sum=0,max_len=0,s_len;
int d[M];
	
bool is_fit(int i,int cur)
{
	for(int j=0;j<len[i];j++)
	{
		if(pri[i][j]!=s[cur+j]) return false;
	}
	return true;
}

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	memset(d,0,sizeof(d));
	char ch[78];
	int i=0;
	while(cin>>ch && ch[0]!='.')
	{
		strcpy(pri[sum],ch);
		len[sum++]=strlen(ch);
	}
	
	while(cin>>ch) strcat(s,ch);
	s_len=strlen(s);
	//puts(s);
	for(int i=s_len-1;i>=0;i--)
	{
		int flag=0;
		for(int j=0;j<sum;j++)
		{
			if((i+len[j]<=s_len) && !(flag&(1<<len[j])) && is_fit(j,i) )
			{
				flag|=(1<<len[j]);
				d[i]=max(d[i],d[i+len[j]]+len[j]);
			}
		}
	}
	int res=0;
//	for(int i=0;i<s_len;i++) {if(d[i]>res) res=d[i];cout<<d[i]<<endl;}
	cout<<d[0]<<endl;
	return 0;
}
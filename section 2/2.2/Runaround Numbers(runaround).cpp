/*ID:maosong1
LANG:C++
PROB:runround
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
bool vis[11];
int L,num[11];
char s[11];
void plus_1()//加1 
{
	int i=0;
	while(i<L)
	{
		if(num[i]+1==10) num[i++]=0;
		else {num[i]++;break;}
	}
	if(i==L) num[L++]++;
	
}
bool is_unique()//每个数位上是数字是否唯一 
{
	memset(vis,false,sizeof(vis));
	for(int i=0;i<L;i++)
	{
		if(vis[num[i]]) return false;
		vis[num[i]]=true;
	}
	
	return true;
}
bool is_fit()//判断是否符合要求 
{

	memset(vis,false,sizeof(vis));
	int pla=L-1,beg=num[L-1];
	for(int i=0;i<L-1;i++)
	{
		pla=((pla-beg)%L+L)%L;
		if(vis[pla]) return false;
		vis[pla]=true;
		beg=num[pla];
	}
	pla=((pla-beg)%L+L)%L;
	if(vis[pla]) return false;
	else return true;
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	cin>>s;
	L=strlen(s);
	memset(num,0,sizeof(num));
	for(int i=0;i<L;i++) num[i]=s[L-i-1]-'0';
	plus_1();
	while(L<10)
	{	
		while(!is_unique())	plus_1();
		if(is_fit()) break;
		else plus_1();
	}
	for(int i=L-1;i>=0;i--) cout<<num[i];
	cout<<endl;
	return 0;
}
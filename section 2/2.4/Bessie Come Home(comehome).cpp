/*ID:maosong1
LANG:C++
PROB:comehome
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#define inf 2139062143
/**
*纯简单题，用一次floyd，然后找出最小值即可。 
**/
using namespace std;
int d[60][60],dis[60],n;
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	memset(d,127,sizeof(d));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char a,b;
		int t;
		cin>>a>>b>>t;
		if(t<d[a-'A'][b-'A']) {d[a-'A'][b-'A']=d[b-'A'][a-'A']=t;}
	}
	for(int i=0;i<60;i++) d[i][i]=0;
	for(int k=0;k<60;k++)
		for(int i=0;i<60;i++)
			for(int j=0;j<60;j++)
				if(d[i][k]!=inf&&d[k][j]!=inf&&d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
	int ans=inf;
	char ch;
	for(int i=0;i<25;i++)
		if(ans>d[i][25]) {ans=d[i][25];ch='A'+i;}
	cout<<ch<<" "<<ans<<endl;
	return 0;
}
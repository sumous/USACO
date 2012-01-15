/*ID:maosong1
LANG:C++
PROB:money
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
long long d[26][10001];
int v,n,coin[25];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>v>>n;
	for(int i=1;i<=v;i++) cin>>coin[i];
	memset(d,0,sizeof(d));
	for(int i=0;i<=v;i++) d[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=v;j++)
		{
			int tmp=i;
			while(tmp>=0){d[j][i]+=d[j-1][tmp];tmp-=coin[j];}
		}
//	for(int i=1;i<=n;i++)
	cout<<d[v][n]<<endl;
	return 0;
}
/*ID:maosong1
LANG:C++
PROB:nocows
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int N,K;
int d[100][200];

int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	cin>>N>>K;
	memset(d,0,sizeof(d));
	for(int i=1;i<=K;i++) d[i][1]=1; 
	for(int i=1;i<=K;i++)
		for(int j=3;j<=N;j++)
			for(int k=1;k<=j-2;k+=2)
			{
				d[i][j]+=d[i-1][k]*d[i-1][j-k-1];
				d[i][j]%=9901;
			}
	cout<<(d[K][N]-d[K-1][N]+9901)%9901<<endl;
	return 0;
}
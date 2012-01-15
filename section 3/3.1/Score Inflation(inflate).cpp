/*ID:maosong1
LANG:C++
PROB:inflate
*/
/**
* 是最小生成树？？？ 
*完全背包问题 
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm> 
#define M 10001
using namespace std;
long f[M],n,m,cos[M],p[M];
int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>m>>n;//cout<<m<<n<<endl; 
	for(long i = 0;i < n;i ++) cin>>p[i]>>cos[i];
	for(long i = 0;i < n;i ++)
		for(long j = 0;j <= m;j ++)
			if(j >= cos[i]) f[j] = max(f[j],f[j - cos[i]]+p[i]);
	long ans = 0;
	for(long i = 0;i <= m;i ++) if(f[i]>ans) ans = f[i];
	cout<<ans<<endl;
	return 0;
} 
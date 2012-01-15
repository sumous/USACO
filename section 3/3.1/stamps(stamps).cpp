/*ID:maosong1
LANG:C++
PROB:stamps
*/
/**
* 枚举，但是有技巧，每个stamps枚举，找到可以使其所需邮票最小的那种
* 直到找到一个不满足d[i]<=K的，输出，退出
* 速度挺快的，看了别人的程序基本没这个快 
* Accepted 
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm> 
#define M 2000001
using namespace std;
int d[M],stamps[51],N,K;
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	memset(d,127,sizeof(d));
	cin>>K>>N;
	for(int i = 0;i < N;i ++) cin>>stamps[i];

	d[1] = 1;d[0] = 0;
	for(int i = 0;i < N;i ++) d[stamps[i]] = 1;
	for(int i = 2;i < M;i ++)
	{
		if(d[i]==1) continue;
		for(int j = N-1;j >= 0;j --)
		{
			int pre = i-stamps[j];
			if(pre>=0)	d[i] = min(d[i],d[pre]+1);

		}
		if(d[i]>K){cout<<i-1<<endl;return 0;}
	}
	return 0;
}
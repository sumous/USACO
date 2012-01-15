/*ID:maosong1
LANG:C++
PROB:humble
*/
/**
* 普通做法当然是一个个枚举，TLE没话说
* 官方标程中，hum[nhum] = min(hum[pindex[i]*prime[i]])
* 这个文字表达很难表达，手算几个数据就清楚是怎么回事了。 
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
long prime[101],hum[100001],k,n,nhum = 1,pindex[101];
int main()
{
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	memset(pindex,0,sizeof(pindex));
	cin>>k>>n;
	for(int i = 0;i < k;i ++) cin>>prime[i];

	hum[0] = 1;
	while(nhum <= n)
	{
		long min = 0x7FFFFFFF,index;
		for(int i = 0;i < k;i ++)
		{
			while(hum[pindex[i]]*prime[i] <= hum[nhum-1]) pindex[i]++;//每个质数对应的都需要修改到比hum[nhum-1]大的值。 
			if(hum[pindex[i]]*prime[i] < min)
			{
				min = hum[pindex[i]]*prime[i];
				index = i;
			}
		}
		hum[nhum++] = min;
		pindex[index]++;
	}
	cout<<hum[n]<<endl;
	return 0;
}
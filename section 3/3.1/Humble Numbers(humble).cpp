/*ID:maosong1
LANG:C++
PROB:humble
*/
/**
* ��ͨ������Ȼ��һ����ö�٣�TLEû��˵
* �ٷ�����У�hum[nhum] = min(hum[pindex[i]*prime[i]])
* ������ֱ����ѱ����㼸�����ݾ��������ô�����ˡ� 
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
			while(hum[pindex[i]]*prime[i] <= hum[nhum-1]) pindex[i]++;//ÿ��������Ӧ�Ķ���Ҫ�޸ĵ���hum[nhum-1]���ֵ�� 
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
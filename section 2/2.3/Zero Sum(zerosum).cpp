/*ID:maosong1
LANG:C++
PROB:zerosum
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const char dic[]=" +-";
int sig[9];
int n;
bool is_zerosum()//判断结果是否为0 
{
	int tmp[17],i,j,k;
	tmp[0]=1;
	for(i=0,j=2,k=1;i<n-1;i++)//先处理空格，即sig[i]==0 
	{
		if(sig[i]!=0){tmp[k++]=sig[i];tmp[k++]=j;j++;}
		else
		{
			int t=tmp[k-1]*10+j;
			tmp[k-1]=t;
			j++;
		}
	}
	int res=tmp[0];
	for(i=1;i<k;i+=2)//在处理加减 
	{
		if(tmp[i]==1) res+=tmp[i+1];
		else res-=tmp[i+1];
	}
	if(res==0) return true;
	else return false;
}
void cout_res()//输出满足的结果 
{
	cout<<"1";
	for(int i=0;i<n-1;i++) cout<<dic[sig[i]]<<i+2;
	cout<<endl;
}
void way(int sel)//枚举方案 
{
	if(sel==n-1)
	{
		if(is_zerosum()) cout_res();
		return;
	}
	for(int i=0;i<3;i++)
	{
		sig[sel]=i;
		way(sel+1);
	}
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	cin>>n;
	way(0);
	return 0;
}
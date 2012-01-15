/*ID:maosong1
LANG:C++
PROB:fracdec
*/
/**
*手算模拟。注意数据1 10000，我栽的地方
*另外，格式的处理上，也出了不少问题的 
**/ 
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	int a,b,intg,end=0,sur=0;
	int dot[100001],loc[100001];
	bool flag=true;
	memset(loc,-1,sizeof(loc));
	cin>>a>>b;
	if(a*100000%b==0) flag=false;
	intg=a/b;
	a%=b;
	/*
	*计算整数位，注意整数位是0的情况 
	*/
	int int_dig=1,tmp=intg;
	if(tmp==0) int_dig++;
	while(tmp!=0){tmp/=10;int_dig++;}
	
	loc[a]=end;
	while(1)
	{
		a*=10;		
		sur=a%b;
		dot[end]=a/b;
		a=sur;
		if(sur==0||(loc[sur]!=-1&&flag)) break;
		loc[sur]=++end;	
	}
	cout<<intg<<".";
	if(sur==0)
		for(int i=0;i<=end;i++) cout<<dot[i];
	else
	{
		for(int i=0;i<=end;i++)
		{
			if((i+int_dig)%76==0&&i!=0) cout<<endl;
			if(i==loc[sur]) {cout<<"(";int_dig++;}
			cout<<dot[i];
		}
		cout<<")";//如果数据强一点，使得括号刚好该换行，这样输出也肯定是有问题的。 
	}
	cout<<endl;	
	return 0;
} 
/*ID:maosong1
LANG:C++
PROB:subset
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
long n;
unsigned long d[391];

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	cin>>n;
	memset(d,0,sizeof(d));
	d[0]=1;
	int aim=n*(n+1)/4;
	if(n*(n+1)%4) cout<<"0"<<endl;
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=aim;j>=i;j--)
				d[j]+=d[j-i];
		cout<<d[aim]/2<<endl;
	}
	return 0;
}
/*ID:maosong1
LANG:C++
PROB:pprime
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define M 10000001
bool prime[M];
long a,b,la;
const long dic[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
long res[10000];
long n=0;
void dfs(long p,int len)
{
	if(len>la || p>b) return;
	long i;
	if(p%10!=0 && p>=a  && prime[p]) res[n++]=p;
	for(i=0;i<=9;i++)
	{
		dfs(p*10+i*dic[len+1]+i,len+2);
	}
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	long i, j;

	scanf("%ld%ld",&a,&b);
	memset(prime,true,sizeof(prime));
	for(i=2;i<=b;i++)
		for(j=i*2;j<=b;j+=i) prime[j]=false;
	la=1;
	long ta=b;
	while(ta/10!=0){ta/=10;la++;}
	for(i = 0;i<=9;i++)
	{
		dfs(i,1);
		dfs(i*10+i,2);
	}
	sort(res,res+n);
	for(i=0;i<n;i++)
	{
		printf("%ld\n",res[i]);
	}
	return 0;
}
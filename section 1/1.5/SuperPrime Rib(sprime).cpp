/*ID:maosong1
LANG:C++
PROB:sprime
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
long m=0;
const long dic[]={2,3,5,7};
long res[10000];
int n;
bool is_prime(long p)
{
	long i;
	for(i=2;i<=sqrt(p);i++)
		if(p%i==0) return false;
	return true;
}
void dfs(long p,int len)
{
	if(len==n) {res[m++]=p;return;}
	long i;
	for(i=1;i<=9;i+=2)
	{
		if(is_prime(p*10+i)) dfs(p*10+i,len+1);
	}
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	int i;

	scanf("%d",&n);
	for(i=0;i<4;i++) dfs(dic[i],1);
	for(i=0;i<m;i++)
	{
		printf("%ld\n",res[i]);
	}
	return 0;
}
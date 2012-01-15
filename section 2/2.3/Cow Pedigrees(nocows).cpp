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

int dfs(int deep,int child)
{	
	if(deep<=0) return -1;
	if(child==1) return 1;
	
	int& ans=d[deep][child];
	if(ans!=-1) return ans;
	ans=0;
	for(int i=1;i<child;i+=2)
	{
		int l=dfs(deep-1,i),r=dfs(deep-1,child-i-1);
		if(l==-1 && r==-1) return -1;
		if(l==-1 && r!=-1) break;
		if(r==-1 && l!=-1) continue;
		ans+=l*r;
	}
	ans%=9901;
	if(ans==0) return -1;
	else return ans;
}
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	cin>>N>>K;
	memset(d,-1,sizeof(d));
	dfs(K,N);dfs(K-1,N);
	cout<<(d[K][N]-d[K-1][N]+9901)%9901<<endl;
	return 0;
}
/*ID:maosong1
LANG:C++
PROB:lamps
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
int N,C,aim[101],ini[101],sum=0;
string res[101];
bool cmp(string a,string b)
{
	return a<b;
}
void is_fit()//确定是否满足最后的条件 
{
	bool flag=true;
	for(int i=0;i<N;i++)
	{
		if(aim[i]==-1) continue;
		if(aim[i]!=ini[i]) {flag=false;break;}
	}
	if(flag)
	{
		for(int i=0;i<N;i++) res[sum]=res[sum]+(char)(!ini[i]+'0');
		sum++;
	}
}
void press(int but)//根据按钮改变状态 
{
	switch(but)
	{
		case 0:
		{
			for(int i=0;i<N;i++) ini[i]=!ini[i];
			break;
		}
		case 1:
		{
			for(int i=0;i<N;i+=2) ini[i]=!ini[i];
			break;
		}
		case 2:
		{
			for(int i=1;i<N;i+=2) ini[i]=!ini[i];
			break;
		}
		case 3:
		{
			for(int i=0;i<N;i+=3) ini[i]=!ini[i];
			break;
		}
	}
}
void way4()//1,2,3,4方案 
{
	for(int i=0;i<4;i++)
	{	
		memset(ini,0,sizeof(ini));
	 	press(i);
	 	is_fit();
 	}
}
void way3()//1、4,2、4,3、4方案
{
	for(int i=0;i<3;i++)
	{
		memset(ini,0,sizeof(ini));
		press(3);
	 	press(i);
	 	is_fit();
	}
}
void way2()//C==2时的方案
{
	way3();
	for(int i=0;i<3;i++)
	{
		memset(ini,0,sizeof(ini));
	 	press(i);
	 	is_fit();
	}
} 

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	cin>>N>>C;
	memset(aim,-1,sizeof(aim));
	memset(ini,0,sizeof(ini));
	int cur;
	while(cin>>cur && cur!=-1)	aim[cur-1]=0;
	while(cin>>cur && cur!=-1)	aim[cur-1]=1;
	
	is_fit();
	if(C==1) way4();
	if(C==2) way2();
	if(C>2) {way4();way3();}
	
	if(sum==0) cout<<"IMPOSSIBLE"<<endl;
	else
	{
		sort(res,res+sum,cmp);
		for(int i=0;i<sum;i++) cout<<res[i]<<endl;
	}
	return 0;
}
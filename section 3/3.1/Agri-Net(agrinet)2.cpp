/*ID:maosong1
LANG:C++
PROB:agrinet
*/
/**
* ��С��������������Kruskal�㷨 
*���ȣ����ߵ�Ȩֵ�Ա߽��д�С�������� 
*Ȼ�󣬴�Ȩֵ��С�ı�ѡ��������ı���ԭ�����������ɻ�·���ò��鼯����ͨ��
*�����������
*ֱ������ı���Ϊn-1��ֹͣ 
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
struct edge
{
	int x,y;
	int val;
}e[5000];

int set[101],sum = 0,n;

bool cmp(edge a,edge b)
{
	return a.val < b.val;
}
int findset(int x)
{
	if(x == set[x]) return x;
	return findset(set[x]);
}

int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	cin>>n;
	for(int i = 0;i < n;i ++) set[i] = i;
	for(int i = 0;i < n;i ++) 
		for(int j = 0;j < n;j ++)
		{
			int tmp;
			cin>>tmp;
			if(j>i)
			{
				e[sum].x = i;e[sum].y = j;
				e[sum++].val = tmp;
			}
		}
	sort(e,e+sum,cmp);
//	for(int i = 0;i < sum;i++) cout<<e[i].val<<endl;
	int count = 1,cur=0,res = 0;
	while(count<n)
	{//cout<<count<<cur<<endl;
		int fx = findset(e[cur].x);
		int fy = findset(e[cur].y);
		if(fx != fy)
		{
			res += e[cur].val;
			set[fy] = fx;
			count++;
		}
		cur++;
	}
	cout<<res<<endl;
	return 0;
}
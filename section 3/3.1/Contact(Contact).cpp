/*ID:maosong1
LANG:C++
PROB:contact
*/
/**
* ����hashö�٣�Ȼ��ת�浽c�ṹ�У���c�ṹ��������
* ��������ע���ʽ��ʱ�临�Ӷ�ΪO(N*len)
* Accepted
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 200001
using namespace std;
struct contact
{
	int fre,pat;
}c[9000];
int has[9000],A,B,N,len,sum = 0;
char s[M];
void fin()//����
{
	cin>>A>>B>>N;
	char str[81];
	gets(s);
	while(gets(str)) strcat(s,str);
	len = strlen(s);
}
void cal()//ͳ��
{
	for(int i = 0;i <= len - A;i ++)
	{
		for(int j = A;j <= B;j ++)
		{
		    if(i+j>len) break;
			int h = 1;
			for(int k = i;k < j+i;k ++) h = (h<<1) + s[k] - '0';
			has[h]++;
		}
	}//cout<<"test";
}
void transfer()//ת�����ṹ
{
	for(int i = (1<<A);i < (1<<(B+1));i ++)
		if(has[i]){c[sum].fre = has[i];c[sum].pat = i;sum++;}
}
bool cmp(contact a, contact b)//sort�ȽϺ���ģ��
{
	if(a.fre > b.fre) return true;
	if(a.fre == b.fre && a.pat<b.pat) return true;
	return false;
}
void print_pat(int a)//���ݴ�����ֵ���������λ������ֵ
{
	int arr[12],t = 0;
	while(a!=1)
	{
		arr[t++] = a&1;
		a>>=1;
	}
	for(int i = t-1;i >= 0;i --) cout<<arr[i];
}
void print()//������
{
	sort(c,c+sum,cmp);
	int t = 1;
	cout<<c[0].fre<<endl;
	print_pat(c[0].pat);
	for(int i = 1;i < sum;i ++)
	{
		if(c[i].fre == c[i-1].fre)
		{
			if(t%6==0) {cout<<endl;print_pat(c[i].pat);}
			else {cout<<" ";print_pat(c[i].pat);}
			t++;
		}
		else
		{
			if(N==1) break;
			cout<<endl<<c[i].fre<<endl;
			print_pat(c[i].pat);
			N--;
			t = 1;
		}
	}
    cout<<endl;
}
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	memset(has, 0,sizeof(has));

	fin();
	cal();
	transfer();
	print();
	return 0;
}

/*ID:maosong1
LANG:C++
PROB:kimbits
*/
/**
* ����+��֦
* �տ�ʼ�Ҵ�0��ʼ�ѣ����ϱ���Ȼ���Ҹĳ�(1<<j)-1��ʼ��
* ���󣬴�nocow�Ͽ�����һ����֦���ǿ�ǳ�����
* ����ɣ��ѵ�1000���������Ҫ��1111��������ʵ��û��Ҫ��
* ֻҪ����I�����Ƿ����1111�����ǵĻ���Ҫ�ҵ�������1000~1111��Χ����
* �ο�λ����http://www.matrix67.com/blog/archives/264
*
**/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <malloc.h>
#include<iostream>
#include<string.h>
#include<string.h>
#define INF 0xFFFFFFFFFFFFFFFF
using namespace std;
const int dic[] = {0x55555555,0x33333333,0x0F0F0F0F,0x00FF00FF,0x0000FFFF};
int N, L, res;
long long I;
int cal_digits(int a)//ͳ�ƶ�������1�ĸ���
{
    for(int i = 0;i < 5;i ++) a = (a&dic[i]) + ((a>>(1<<i))&dic[i]);
    return a;
}
void fin()//����
{
    cin>>N>>L>>I;
}
void cal()//Ѱ��
{
    long long count;
    int j = L;
    while((1<<j)-1>=I) j--;//�ҳ����������j
    count = (1<<j)-1;
    for(int i = count;i <= INF;i ++)
    {
        int p = cal_digits(i), t=0;
        if(p>L) continue;
        int tmp = 1<<(L-p);
        if(!(i&(tmp-1)))//��������i��β������L-pλȫΪ1��������֦
            if(count+(1<<(L-p)) < I)
            {
                i += tmp-1;
                count += tmp-1;
            }
            else//˵��Ҫ���������i+I-count-1
            {
                res = i+I-count-1;
                break;
            }
        count++;
        if(count == I){res = i;break;}
    }
}
void fout()//���
{
    int a[32],i = 0;
    while(res != 0)
    {
        a[i++] = res&1;
        res>>=1;
    }
    for(int j = 0;j < N-i;j ++) cout<<"0";
    for(int j = i-1;j >= 0;j --) cout<<a[j];
    cout<<endl;
}
int main()
{
    freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
    fin();
    cal();
    fout();
    return 0;
}

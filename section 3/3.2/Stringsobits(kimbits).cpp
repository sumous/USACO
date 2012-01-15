/*ID:maosong1
LANG:C++
PROB:kimbits
*/
/**
* 搜索+剪枝
* 刚开始我从0开始搜，果断爆，然后，我改成(1<<j)-1开始搜
* 而后，从nocow上看到了一个剪枝，是快非常多了
* 比如吧，搜到1000，这里如果要到1111，这样其实是没必要的
* 只要看第I个数是否大于1111，不是的话，要找的数就在1000~1111范围里了
* 参考位运算http://www.matrix67.com/blog/archives/264
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
int cal_digits(int a)//统计二进制中1的个数
{
    for(int i = 0;i < 5;i ++) a = (a&dic[i]) + ((a>>(1<<i))&dic[i]);
    return a;
}
void fin()//输入
{
    cin>>N>>L>>I;
}
void cal()//寻找
{
    long long count;
    int j = L;
    while((1<<j)-1>=I) j--;//找出满足的最大的j
    count = (1<<j)-1;
    for(int i = count;i <= INF;i ++)
    {
        int p = cal_digits(i), t=0;
        if(p>L) continue;
        int tmp = 1<<(L-p);
        if(!(i&(tmp-1)))//尝试着在i的尾部加上L-p位全为1的数，剪枝
            if(count+(1<<(L-p)) < I)
            {
                i += tmp-1;
                count += tmp-1;
            }
            else//说明要求的数在是i+I-count-1
            {
                res = i+I-count-1;
                break;
            }
        count++;
        if(count == I){res = i;break;}
    }
}
void fout()//输出
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

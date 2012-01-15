/*ID:maosong1
LANG:C++
PROB:fact4
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <malloc.h>
#include<iostream>
#include<string.h>
#include<string.h>
using namespace std;
/**
* ������˸���ǰ�ù��ļ���߾��Ƚ׳˵ĳ���
* С�޸�һ�¾͹��ˣ���0��
**/
void calcFac(unsigned long n)
{
    unsigned long i,j,head,tail;
    int blkLen=(int)(n*log10((n+1)/2)); //����n!�������ֵĸ���
    blkLen+=4;  //������������4λ

    char *arr=(char *)malloc(blkLen);

    memset(arr,0,sizeof(char)*blkLen);
    head=tail=blkLen-1;
    arr[tail]=1;

    for (i=2;i<=n;i++)
    {
        unsigned long c=0;
        for (j=tail;j>=head;j--)
        {
            unsigned long prod=arr[j] * i +c;
            arr[j]=(char)( prod % 10);
            c= prod / 10;
        }
        while (c>0)
        {
            head--;
            arr[head]=(char)(c % 10);
            c/=10;
        }
    }
    for (i=tail;i>=head;i--)
        if(arr[i]!=0){ printf("%c\n",arr[i]+'0');return;}
    free(arr);
}

void testCalcFac()
{
    freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
    int n;
    scanf("%ld",&n);

    calcFac(n);
}

int main()
{
    testCalcFac();
    return 0;
}

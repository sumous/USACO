/*ID:maosong1
LANG:C++
PROB:shopping
*/
/**
* ���ر�������
* �Ƚϸ��ӡ�
* ״̬��f[b1][b2][b3][b4][b5] ��bi����Ʒi��i=1..5��ʱ���Ż��ܽ�Լ�ļ۸�
* ���淽�̣�f[b1][b2][b3][b4][b5] =  f[b1][b2][b3][b4][b5] = max{f[b1][b2][b3][b4][b5],
*    f[b1-m1*j][b2-m2*j][b3-m3*j][b4-m4*j][b5-m5*j] + a[i].v*j} ( j = 0..5 )
* PS����������ܹ���Լ�۸�Ȼ�����ܼ۸��ȥ��Լ�ļ۸�Ϊ��
**/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/* v��ʾ�Żݺ�ļ۸�k[]��ʾ��Ʒ�����Ӧ���� */
struct reduce
{
    int v, k[1001];
}a[100];
/* id��Ʒ���룻n��Ӧ��Ʒ������p�۸� */
struct per
{
    int id, n, p;
}b[6];

int s1, s2, f[6][6][6][6][6];
int sum = 0, M = 0;


void load()
{
    freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
    /**
    * �����Żݴ�ʩ����c[i][0]��ʾn�� a[i][1000]��ʾp
    **/
    cin>>s1;
    for (int i = 0;i < s1;i++)
    {
        int num;
        cin>>num;
        for (int j = 1;j <= num;j++)
        {
            int tmp;
            cin>>tmp;
            cin>>a[i].k[tmp];
        }
        cin>>a[i].v;
    }
    //���빺����Ŀ
    cin>>s2;
    for (int i = 0;i < s2;i++)
    {
        cin>>b[i].id>>b[i].n>>b[i].p;
        sum += b[i].n * b[i].p;
    }
    //����ÿ���Żݷ�ʽ��Լ�ļ۸�
    for (int i = 0;i < s1;i++)
    {
        int sval = 0;
        for (int j = 0;j < s2;j++)
            sval += a[i].k[ b[j].id ] * b[j].p;
        a[i].v = sval - a[i].v;
    }

}
void Knapsack()//���ر���
{
    memset(f, 0, sizeof(f));
   // f[0][0][0][0][0] = 0;

    for (int i = 0;i < s1;i++)
    {
        int m1, m2, m3, m4, m5;
        m1 = a[i].k[ b[0].id ];
        m2 = a[i].k[ b[1].id ];
        m3 = a[i].k[ b[2].id ];
        m4 = a[i].k[ b[3].id ];
        m5 = a[i].k[ b[4].id ];
        for (int b1 = b[0].n; b1 >= m1;b1--)
            for (int b2 = b[1].n; b2 >= m2;b2--)
                for (int b3 = b[2].n; b3 >= m3;b3--)
                    for (int b4 = b[3].n; b4 >= m4;b4--)
                        for (int b5 = b[4].n; b5 >= m5;b5--)
                        { //cout<<b1<<" "<<b2<<" "<<b3<<" "<<b4<<" "<<b5<<" "<<f[b1][b2][b3][b4][b5]<<endl;
                            for (int j = 1;j <= 5;j++)
                            //���ر�����ǰ�������鲻Խ��
                                if ( b1>=m1*j && b2>=m2*j && b3>=m3*j && b4>=m4*j && b5>=m5*j )
                                    f[b1][b2][b3][b4][b5] = max(f[b1][b2][b3][b4][b5], f[b1-m1*j][b2-m2*j][b3-m3*j][b4-m4*j][b5-m5*j]+a[i].v*j);

                            M = max(M, f[b1][b2][b3][b4][b5]);
                        }
    }
}
void out()//���
{
    cout<<sum-M<<endl;
    fclose(stdin);
    fclose(stdout);
}
int main()
{
	load();
	Knapsack();
	out();
    return 0;
}

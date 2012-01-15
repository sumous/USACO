/*ID:maosong1
LANG:C++
PROB:game1
*/
/**
* ̫�����һ�����ˡ���ȫû�о�����Ȼ���Ƕ�̬�滮��
* �������⡣
* �����г���ÿ��ȡ�Լ����������ʵҲ�����öԷ�
* ������С��
* sum[i][j]:��i��j�������ĺ�
* d[i][j]:��ǰ״̬�£�ȡ�����ܵõ������Ч��
* d[i][j] = sum[i][j] - min( d[i][j-1], d[i+1][j] )
* (i = n...1, j = i+1...n)
**/
#include <iostream>
#include <fstream>
#define EXE 1
using namespace std;
int sum[252][252] = {0}, d[252][252] = {0}, n;
int s[252];
void load()
{
    fstream fin;
    fin.open("game1.in", ios::in);
    fin>>n;
    /* �������� */
    for (int i = 1; i <= n; i++) fin>>s[i];
    fin.close();
}
/* �ö�̬�滮����d[i][j] */
void dp()
{
    /* ����sum[i][j] */
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum[i][j] = sum[i][j-1] + s[j];
        }
    }
    /* ����d[i][j] */
    for (int i = 1; i <= n; i++) d[i][i] = s[i];
    for (int i = n; i > 0; i--)
        for (int j = i+1;j <= n; j++)
        {
            //if(i == j) continue;
            d[i][j] = sum[i][j] - min(d[i][j-1], d[i+1][j]);
        }
}
void out()
{
    #if EXE == 1
        fstream fout;
        fout.open("game1.out", ios::out);
        fout<<d[1][n]<<" "<<sum[1][n]-d[1][n]<<endl;
        fout.close();
    #else
        cout<<d[1][n]<<" "<<sum[1][n]-d[1][n]<<endl;
    #endif
}
int main()
{
    load();
    dp();
    out();
    return 0;
}

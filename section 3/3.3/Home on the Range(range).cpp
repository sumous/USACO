/*ID:maosong1
LANG:C++
PROB:range
*/
/**
* ��̬�滮
* ״̬��d[x][y]:(x, y)��Ϊ���������϶��㣬������ɵ�
* ����������
* ���̣�d[x][y] = min(d[x+1][y], d[x][y+1], d[x+1][y+1]) + 1
* Ȼ��ö��ÿ����(i, j)��Ϊ���������϶���ʱ����Ӧ��������sn[n]+1(n=2..d[i][j])
**/
#include <iostream>
#include <fstream>
#define EXE 1
using namespace std;
int d[252][252] = {0}, n, map[252][252], sn[252] = {0};
bool vis[252][252] = {false};
/* �������� */
void load()
{
    fstream fin;
    fin.open("range.in", ios::in);
    fin>>n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char ch;
            fin>>ch;
            map[i][j] = ch - '0';

        }

    fin.close();
}
/* �ж��Ƿ�Խ�� */
bool is_over(int x, int y)
{
    if ( (x<1) || (x>n) || (y<1) || (y>n) ) return true;
    else return false;
}
/* �ж�(x+1,y)(x,y+1)(x+1,y+1)�Ƿ�Խ�� */
bool three_over(int x, int y)
{
    if (is_over(x+1, y) || is_over(x, y+1) || is_over(x+1, y+1))
        return true;
    else return false;
}

/* �ҳ�����������Сֵ */
int min_three(int a, int b, int c)
{
    return min( min(a, b), c );
}
/* �ö�̬�滮�������� */
void dp()
{
    for (int i = n; i > 0; i--)
        for (int j = n; j > 0; j--)
        {
            if(map[i][j])
            {
                if(!three_over(i, j))
                {//cout<<i<<" "<<j<<endl;
                    d[i][j] = min_three(d[i+1][j], d[i][j+1], d[i+1][j+1]) + 1;
                }
                else d[i][j] = 1;
            }
            else d[i][j] = 0;
        }
}
/* ����d[][]������sn[] */
void work()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int size = d[i][j];
            for (int k = 2; k <= size; k++)
                sn[k]++;
        }
    }
}
/* ��� */
void out()
{
    #if EXE == 1
        fstream fout;
        fout.open("range.out", ios::out);
        for (int i = 2; i <= n; i++)
            if (sn[i]) fout<<i<<" "<<sn[i]<<endl;
    #else
        for (int i = 2; i <= n; i++)
            if (sn[i]) cout<<i<<" "<<sn[i]<<endl;
    #endif
}
int main()
{
    load();
    dp();
    work();
    out();
    return 0;
}

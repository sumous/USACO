/*ID:maosong1
LANG:C++
PROB:ratios
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int goal[3], three[3][3], ratios[3], mul;
void load()//��������
{
    for(int i = 0;i < 3;i ++) cin>>goal[i];
    for(int i = 0;i < 3;i ++)
        for(int j = 0;j < 3;j ++) cin>>three[i][j];
}
bool is_fit(int a[])
{
    bool flag = true;
    for(int i = 0;i < 3;i ++)
        if(goal[i]!=0 && (a[i]%goal[i])) flag = false;
    if(flag)
    {
        for(int i = 0;i < 3;i ++)
            if(goal[i] && a[i]) {mul = a[i] / goal[i];break;}


        for(int i = 0;i < 3;i ++)
            if(goal[i]*mul != a[i]) return false;
        return true;
    }
    else return false;
}

bool deal()
{
    //ö�����������ϵ��
    for(ratios[0] = 0;ratios[0] <= 100;ratios[0] ++)
        for(ratios[1] = 0;ratios[1] <= 100;ratios[1] ++)
            for(ratios[2] = 0;ratios[2] <= 100;ratios[2] ++)
            {
                int a[3] = {0,0,0};
                bool flag = true;
                //���㵱ǰϵ���µõ�goal��Ӧ��ֵ��ǰ���Ƕ�Ӧgoal�м������õ���a������Ӧ��goal
                for(int i = 0;i < 3;i ++)
                {
                    for(int j = 0;j < 3;j ++)
                        a[i] += ratios[j]*three[j][i];
                    if(a[i]<goal[i]){flag = false;break;}
                }
                //�ж��Ƿ�������goal�ɱ���
                if(flag && is_fit(a)) return true;
            }
    return false;

}
int main()
{
    freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
    load();
    if(deal())
    {
        for(int i = 0;i < 3;i ++) cout<<ratios[i]<<" ";
        cout<<mul<<endl;
    }
    else cout<<"NONE"<<endl;
    return 0;
}

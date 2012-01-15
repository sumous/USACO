/*ID:maosong1
LANG:C++
PROB:ratios
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int goal[3], three[3][3], ratios[3], mul;
void load()//输入数据
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
    //枚举所以满足的系数
    for(ratios[0] = 0;ratios[0] <= 100;ratios[0] ++)
        for(ratios[1] = 0;ratios[1] <= 100;ratios[1] ++)
            for(ratios[2] = 0;ratios[2] <= 100;ratios[2] ++)
            {
                int a[3] = {0,0,0};
                bool flag = true;
                //计算当前系数下得到goal对应的值，前提是对应goal中加起来得到的a大于相应的goal
                for(int i = 0;i < 3;i ++)
                {
                    for(int j = 0;j < 3;j ++)
                        a[i] += ratios[j]*three[j][i];
                    if(a[i]<goal[i]){flag = false;break;}
                }
                //判断是否满足与goal成比例
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

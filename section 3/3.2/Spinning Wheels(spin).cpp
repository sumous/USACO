/*ID:maosong1
LANG:C++
PROB:spin
*/
/**
*纯模拟题，我以为有什么特别的呢
**/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int speed[5], wedge[5][5][2], num[5], times = 0;
void load()
{
    for(int i = 0;i < 5;i ++)
    {
        cin>>speed[i]>>num[i];
        for(int j = 0;j < num[i];j ++)  cin>>wedge[i][j][0]>>wedge[i][j][1];
    }
}
bool is_full()
{
    int flag[360];
    memset(flag, 0, sizeof(flag));
    for(int i = 0;i < 5;i ++)
    {//if(t==9)cout<<wedge[i][0][0]<<endl;
        for(int j = 0;j < num[i];j ++)
        {
            int start = wedge[i][j][0], end = wedge[i][j][0]+wedge[i][j][1];
            for(int k = start;k <= end;k ++)
            {//cout<<k<<" ";
                int cur = k%360;
                flag[cur]++;
            }
        }
    }
    for(int i = 0;i < 360;i ++)
    {
       // cout<<flag[i]<<" ";
        if(flag[i]==5) return false;
    }
    return true;
}
void flow()
{
    for(int i = 0;i < 5;i ++)
    {
        for(int j = 0;j < num[i];j ++)
            wedge[i][j][0] = (wedge[i][j][0] + speed[i])%360;
    }
}
bool deal()
{
    for(int i = 0;i < 360;i ++)
    {
        if(!is_full()){times = i;return true;}
        flow();
    }
    return false;
}

int main()
{
    freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
    load();
    if(deal()) cout<<times<<endl;
    else cout<<"none"<<endl;
    return 0;
}

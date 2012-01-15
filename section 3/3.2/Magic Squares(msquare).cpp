/*ID:maosong1
LANG:C++
PROB:msquare
*/
/*******************************************

第一次尝试用类来建立对象，还是比较顺利的。
但是面对对象的概念没体现。
这里用bfs（广搜）：每搜到一个结点，进行三
次变化，如果没被访问过，就把它加入q里。
PS:
status：用七维数组（前七个确定了，第八个当然
确定了）记录是否被访问。
target：需要达到的目的地
有一组数据需要考虑：1 2 3 4 5 6 7 8

********************************************/
#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

class queues
{
    public:
        int square[9];
        char str[60];
    public:

        void reset(int square[], char *str)
        {
            for(int i = 0;i < 8;i ++) this->square[i] = square[i];
            strcpy(this->str, str);
        }
        void copy(queues q)
        {
            for(int i = 0;i < 8;i ++) this->square[i] = q.square[i];
            strcpy(this->str, q.str);
        }
};
bool status[9][9][9][9][9][9][9];
int target[9];
char res[60];
queues q[40325];
const char tfm[] = "ABC";

void init()
{
    for(int i = 0;i < 8;i ++) cin>>target[i];
    memset(status, false , sizeof(status));
    status[1][2][3][4][5][6][7] = true;
    int square[9];
    char str[] = "";
    for(int i = 0;i < 8;i ++) square[i] = i+1;
    q[0].reset(square, str);
}
bool is_target(int* square)//判断是否到达目的
{
    for(int i = 0;i < 7;i ++)
        if(square[i]!=target[i]) return false;
    return true;
}
void swap(int& a, int& b)
{
    int tmp = a;
    a = b, b = tmp;
}
void transmation(int* square, char opt)//根据opt进行变化
{
    if(opt=='A')
    {
        for(int i = 0,j = 7;i < 4;i++,j--) swap(square[i], square[j]);
    }
    else if(opt=='B')
    {
        int tmp = square[3];
        for(int i = 3;i >= 0;i --) square[i] = square[i-1];
        square[0] = tmp;

        tmp = square[4];
        for(int i = 4;i < 7;i ++) square[i] = square[i+1];
        square[7] = tmp;
    }
    else
    {
        int tmp = square[1];
        square[1] = square[6],square[6] = square[5],square[5] = square[2];
        square[2] = tmp;
    }
}

void bfs()
{
    int i = 0,rear = 1;
    while(1)
    {
        queues cur;
        cur.copy(q[i++]);
        if(is_target(cur.square)){strcpy(res, cur.str);res[strlen(res)]='\0';return;}//到达目的了，返回
        for(int j = 0;j < 3;j ++)
        {
            char str[60];
            int square[9];
            for(int k = 0;k < 8;k ++) square[k] = cur.square[k];
            transmation(square, tfm[j]);
            strcpy(str, cur.str);
            int len = strlen(str);
            str[len] = tfm[j];
            str[len+1] = '\0';


            bool& flag = status[square[0]][square[1]][square[2]][square[3]][square[4]][square[5]][square[6]];
            if(!flag)//未被访问
            {
                flag = true;
                q[rear++].reset(square, str);
            }
        }
    }
}
int main()
{
    freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
    init();
    bfs();
    cout<<strlen(res)<<endl;
    cout<<res<<endl;
    return 0;
}

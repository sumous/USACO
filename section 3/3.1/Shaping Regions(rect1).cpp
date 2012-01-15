/*ID:maosong1
LANG:C++
PROB:rect1
*/
/**
* 矩形分割，看了那个叫什么矛的论文，才知道有这么个高效的算法啊
* 不过，我虽然懂了原理，但是不知道怎么写，看了一下别人的代码
* 总算理解了。这代码具有高仿性哈
**/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
#define M 10001
using namespace std;
struct rectangle
{
    int llx,lly,urx,ury,color;
}rec[M];
int N;
int area[2501];

void cut(int llx,int lly,int urx,int ury,int c,int floor)
{
    while((floor<=N) && ((llx>=rec[floor].urx)||(lly>=rec[floor].ury)||(urx<=rec[floor].llx)||(ury<=rec[floor].lly))) floor++;
    if(floor>N){area[c] += (urx-llx)*(ury-lly);return;}
    if(llx<rec[floor].llx){cut(llx,lly,rec[floor].llx,ury,c,floor+1);llx = rec[floor].llx;}
    if(urx>rec[floor].urx){cut(rec[floor].urx,lly,urx,ury,c,floor+1);urx = rec[floor].urx;}
    if(lly<rec[floor].lly){cut(llx,lly,urx,rec[floor].lly,c,floor+1);lly = rec[floor].lly;}
    if(ury>rec[floor].ury){cut(llx,rec[floor].ury,urx,ury,c,floor+1);ury = rec[floor].ury;}
}
int main()
{
    freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
    memset(area,0,sizeof(area));
    cin>>rec[0].urx>>rec[0].ury>>N;
    for(int i = 1;i <= N;i ++) cin>>rec[i].llx>>rec[i].lly>>rec[i].urx>>rec[i].ury>>rec[i].color;
    rec[0].llx = rec[0].lly = 0;rec[0].color = 1;

    for(int i = N;i >= 0;i --) cut(rec[i].llx,rec[i].lly,rec[i].urx,rec[i].ury,rec[i].color,i+1);
    for(int i = 1;i <= 2500;i ++) if(area[i]) cout<<i<<" "<<area[i]<<endl;
    return 0;
}

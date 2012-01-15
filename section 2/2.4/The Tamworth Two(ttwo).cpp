/*ID:maosong1
LANG:C++
PROB:ttwo
*/
/**
*ģ���⡣�и���������˺ܾã��������п�����һ�����ڻ���һ������ѭ��
*�������룬�и����޵ģ�����ﵽ������޾Ϳ϶���һֱ���ظ���
*��ô���ڴﵽ���޵�ʱ����ѭ���˳�������
*���⼫�ޣ�ȡ���ʵ����ɣ���û����ô�࣬ȡ10000
*Accepted 
**/ 
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string.h>
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
char map[11][11];
int fx,fy,cx,cy,fd=0,cd=0;
bool is_ok(int x,int y)
{
	if((x>=0&&x<10)&&(y>=0&&y<=10)) return true;
	return false;
}
int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);

	for(int i=0;i<10;i++) cin>>map[i];
	int sum=0;
	for(int i=0;i<10;i++) 
		for(int j=0;j<10;j++)
		{
			if(map[i][j]=='C'){cx=i;cy=j;map[i][j]='.';}
			if(map[i][j]=='F'){fx=i;fy=j;map[i][j]='.';}
		}
	while(!(fx==cx && fy==cy))	
	{
		sum++;
		int nx=fx+dx[fd],ny=fy+dy[fd];
		if(is_ok(nx,ny)&&map[nx][ny]=='.'){fx=nx;fy=ny;}
		else fd=(fd+1)%4;
		nx=cx+dx[cd],ny=cy+dy[cd];
		if(is_ok(nx,ny)&&map[nx][ny]=='.'){cx=nx;cy=ny;}
		else cd=(cd+1)%4;
		if(sum==10000){sum=0;break;}
	}
	cout<<sum<<endl;
	return 0;
}
/*ID:maosong1
LANG:C
PROB:ariprog
*/
#include<stdio.h>
#include<math.h>
int n, m;
#define MAX 130000

int bisn[MAX] = {0};



int is_bis(int a, int b)//判断此时的a,b是否满足双平方集合 
{
	int i;
	for(i = 0;i < n;i ++)
	{
		if(!bisn[a+i*b]) return 0;
	}
	return 1;
}

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	
	
	int  result[10005][2];
	scanf("%d%d", &n, &m);
	
	
	int i, j,  cur = 0;
	long max = m*m*2;
	for(i = 0;i <= m; i++)
	{
		for(j = 0;j <= i;j ++)
			bisn[i*i+j*j] = 1;
	}
	
	for(i = 1;i <= max /(n - 1);i++)
	{
		//if(!bisn[i]) continue;
		for(j = 0;j <= max - (n-1)*i;j ++ )
		{
			if(!bisn[j+i]||!bisn[j]) continue;
			if(is_bis(j,i))
			{
				result[cur][0] = j;
				result[cur][1] = i;
				cur ++;
			}
		}
	}
	
	if(cur == 0) printf("NONE\n");
	else
		for(i = 0;i < cur;i ++)
			printf("%d %d\n", result[i][0], result[i][1]);
	return 0;
}
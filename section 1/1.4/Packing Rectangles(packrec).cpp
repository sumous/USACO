/*ID:maosong1
LANG:C
PROB:packrec
*/
#include<stdio.h>
#include<stdlib.h>

const int r[][4]={{0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},
				  {1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},
				  {2,1,0,3},{2,1,3,0},{2,0,1,3},{2,0,3,1},{2,3,1,0},{2,3,0,1},
				  {3,1,2,0},{3,1,0,2},{3,2,1,0},{3,2,0,1},{3,0,1,2},{3,0,2,1},};
const int c[][4][2]={{{0,1},{0,1},{0,1},{0,1}},
					  {{0,1},{0,1},{0,1},{1,0}},
					  {{0,1},{0,1},{1,0},{0,1}},
					  {{0,1},{0,1},{1,0},{1,0}},
					  {{0,1},{1,0},{0,1},{0,1}},
					  {{0,1},{1,0},{0,1},{1,0}},
					  {{0,1},{1,0},{1,0},{0,1}},
					  {{0,1},{1,0},{1,0},{1,0}},
					  {{1,0},{0,1},{0,1},{0,1}},
					  {{1,0},{0,1},{0,1},{1,0}},
					  {{1,0},{0,1},{1,0},{0,1}},
					  {{1,0},{0,1},{1,0},{1,0}},
					  {{1,0},{1,0},{0,1},{0,1}},
					  {{1,0},{1,0},{0,1},{1,0}},
					  {{1,0},{1,0},{1,0},{0,1}},
					  {{1,0},{1,0},{1,0},{1,0}}};
int data[4][2];
int m=10005;
int res[10000][2],n=0,tail=0;
int cmp(const void *a1,const void* a2)
{
	return ((int *)a1)[0]-((int *)a2)[0];
}

void insert(int a,int b)
{
	if(a>b) {res[tail][0]=b;res[tail][1]=a;tail++;}
	else {res[tail][0]=a;res[tail][1]=b;tail++;}	
}
void test(int a,int b)
{
	int s=a*b;//printf("%d %d %d\n",a,b,s);
	if(s<m){m=s;tail=0;insert(a,b);}
	else if(s==m) insert(a,b);
} 
void find_min(int way[][2])
{
	int max_a=way[0][0],sum_b=way[0][1],i;
	/*方案一*/
	
	for(i = 1;i<4;i++)
	{
		if(way[i][0]>max_a) max_a=way[i][0];
		sum_b+=way[i][1];
	}
	test(max_a,sum_b);
	
	/*方案二*/
	max_a=way[0][0],sum_b=way[0][1];
	for(i = 1;i<3;i++)
	{
		if(way[i][0]>max_a) max_a=way[i][0];
		sum_b+=way[i][1];
	}
	if(sum_b<way[3][0]) sum_b=way[3][0];
	max_a+=way[3][1];
	test(max_a,sum_b);
	
	/*方案三*/	
	sum_b=way[0][1]+way[1][1];
	max_a=way[0][0]>way[1][0]?way[0][0]:way[1][0];
	if(sum_b<way[2][0]) sum_b=way[2][0];
	max_a+=way[2][1];
	sum_b+=way[3][1];
	if(max_a<way[3][0]) max_a=way[3][0];
	test(max_a,sum_b);
	
	/*方案四*/
	max_a=way[0][0],sum_b=way[0][1];
	for(i = 1;i<3;i++)
	{
		if(way[i][0]>max_a) max_a=way[i][0];
		sum_b+=way[i][1];
	}
	if(way[3][1]<=way[1][1])
	{
		if(way[3][0]+way[1][0]>max_a) test(way[3][0]+way[1][0],sum_b);
		else test(max_a,sum_b);
	}
	
	/*方案五*/
	max_a=way[0][0]+way[1][0];
	sum_b=way[0][1]>way[1][1]?way[0][1]:way[1][1];
	for(i = 2;i<4;i++)
	{
		if(way[i][0]>max_a) max_a=way[i][0];
		sum_b+=way[i][1];
	}
	test(max_a,sum_b);
	
	/*方案六*/
	if(way[1][0]<=way[3][0] && way[0][1]<=way[1][1])
	{
	if(way[0][0]+way[1][0]>way[2][0]+way[3][0]) max_a=way[0][0]+way[1][0];
	else max_a=way[2][0]+way[3][0];
	if(way[0][1]+way[2][1]>way[1][1]+way[3][1]) sum_b=way[0][1]+way[2][1];
	else sum_b=way[1][1]+way[3][1];
	}
	else
	{
		if(way[0][0]+way[1][0]>way[2][0]+way[3][0]) max_a=way[0][0]+way[1][0];
		else max_a=way[2][0]+way[3][0];
		sum_b=way[0][1]>way[1][1]?way[0][1]:way[1][1];
		sum_b+=way[2][1]>way[3][1]?way[2][1]:way[3][1];
	}
	test(max_a,sum_b);
}
int main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	int i,j,k,l;
	for(i = 0 ;i < 4;i ++) scanf("%d %d\n",&data[i][0],&data[i][1]);
	for(i = 0;i < 24;i++)
		for( j = 0;j < 16;j++)
		{
			int way[4][2];
			for(k = 0;k < 4;k++)
				for(l = 0;l < 2;l++)
					way[k][l]=data[r[i][k]][c[j][k][l]];
			find_min(way);
		}

	printf("%d\n",m);
	qsort(res,tail,sizeof(int)*2,cmp);
	printf("%d %d\n",res[0][0],res[0][1]);
	for(i = 1;i < tail;i++)
	{
		if(res[i][0]==res[i-1][0]) continue;
		printf("%d %d\n",res[i][0],res[i][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
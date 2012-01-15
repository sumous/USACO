/*ID:maosong1
LANG:C
PROB:clocks
*/
#include<stdio.h>
#include<math.h>
/**
**�����Ǳ任���������� 
**/
const float move_ver[9][9]={{-0.5,0.5,0,1,0,-0.5,-0.5,-0.5,1},
						    {-0.5,-0.5,1,1,1,-0.5,-1.5,0.5,0},
					        {1,1,-1,-2,-1,1,2,0,-1},
						    {1,0,-1,-1,0,1,1,0,-1},
						    {1,0,0,-1,-1,0,1,0,0},
						    {-1.5,-0.5,1,2,1,-0.5,-1.5,-0.5,1},
						    {-0.5,-0.5,1,1,0,-0.5,-0.5,0.5,0},
						    {0,1,-1,-1,0,0,1,0,0},
						    {0.5,-0.5,0,0,0,0.5,-0.5,0.5,0}};
int main()
{
	int  sol[36] = {0};
	float clock[9],num[9] = {0.0};
	int i, j, temp;
	
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	
	/**
	**�������ݣ�������ת��Ϊ0��1��2��3��
	**����4ȥ�� 
	**/
	for(i = 0;i < 9;i ++)
	{
		scanf("%d", &temp);
		clock[i] = 4 - temp/3;
	} 
	
	/**
	**����˷���clock&&move_ver�� 
	**/
	for(i = 0; i < 9;i ++)
	{
		temp = 0;
		for(j = 0;j < 9;j ++)
		{
			temp += floor(clock[j]*move_ver[j][i]+0.5);
		}
		num[i] = temp%4;
			printf("%d\n",temp);
	} 

	int  count = 0;
/*	for(i = 0;i < 9;i ++)
	{
		if(num[i] != 0.0)
		{
			for(j = count;j < count+int(num[i]+0.5);j ++)
			{
				sol[j] = i + 1;	
			}
			count += int(num[i]+0.5);
		}
	}
	
	for(i = 0;i < count - 1;i++)
		printf("%d ", sol[i]);
	printf("%d\n", sol[count-1]);*/
	for(i = 0;i < 9;i ++) printf("%f ", num[i]);
	return 0;
}
 
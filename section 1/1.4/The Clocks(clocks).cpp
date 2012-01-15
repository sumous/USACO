/*ID:maosong1
LANG:C
PROB:clocks
*/
#include<stdio.h>
#include<string.h>
//const char move[9][6]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
const int move[9][9]={{3,3,0,3,3,0,0,0,0},
					  {3,3,3,0,0,0,0,0,0},
					  {0,3,3,0,3,3,0,0,0},
					  {3,0,0,3,0,0,3,0,0},
					  {0,3,0,3,3,3,0,3,0},
					  {0,0,3,0,0,3,0,0,3},
					  {0,0,0,3,3,0,3,3,0},
					  {0,0,0,0,0,0,3,3,3},
					  {0,0,0,0,3,3,0,3,3}};
int sol[36];
int s[9];


int is_find(int* s1)//判断是否已经找到 
{
	int i;	
	for(i = 0;i < 9;i++)
	{
		if(s1[i]%12 != 0) return 0;
	}	
	return 1;
}
int programed(int* num)//根据传来的个方法对应的个数判断 
{
	int i, j, s1[9];
	for(i = 0;i < 9;i ++)
		s1[i] = s[i];
	for(i = 0;i < 9;i ++)
	{
		for(j = 0; j < 9;j ++)
			s1[j] += num[i]*move[i][j];
	}
		
	return is_find(s1);
	
}
int find_solution()//按传过来的值出来处理数据 
{
	int a1, a2, a3, a4, a5, a6, a7, a8, a9;
	for( a1 = 0;a1 < 4;a1++)
		for( a2 = 0;a2 < 4;a2++)
			for( a3 = 0;a3 < 4;a3++)
				for( a4 = 0;a4 < 4;a4++)
					for( a5 = 0;a5 < 4;a5++)
						for( a6 = 0;a6 < 4;a6++)
							for( a7 = 0;a7 < 4;a7++)
								for( a8 = 0;a8 < 4;a8++)
									for( a9 = 0;a9 < 4;a9++)
									{
										int num[9]={a1,a2,a3,a4,a5,a6,a7,a8,a9};
										if(programed(num))
										{
											int i, j, count = 0;
											for(i = 0;i < 9;i ++)
											{
												if(num[i] != 0)
												{
													for(j = count;j < count+num[i];j ++)
													{
														sol[j] = i + 1;	
													}
													count += num[i];
												}
												
											}
											return count;
										}
									}
return 0;
}
int main()
{
	FILE *fin, *fout;
	fin = fopen("clocks.in", "r");
	fout = fopen("clocks.out", "w");
	int i;
	
	for(i = 0; i < 9;i ++) 
		fscanf(fin,"%d", &s[i]);	
	


	int n = find_solution();
//	printf("test");
	for(i = 0;i < n - 1;i++)
		fprintf(fout,"%d ", sol[i]);
	fprintf(fout,"%d\n", sol[n-1]);
	return 0;
}
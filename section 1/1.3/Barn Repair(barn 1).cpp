/*ID:maosong1
LANG:C
PROB:barn1
*/
#include<stdio.h>
#include<stdlib.h> 
int comp(const void *a,const void *b)//һά��������ȽϺ��� 
{
	return *(int *)a - *(int *)b;
} 
int main()
{
	FILE *fin , *fout;
	fin = fopen( "barn1.in" , "r" );
	fout = fopen( "barn1.out" , "w" );
	
	int M , S , C , i , stall_num[205] , result ;
	int emp[205] , div = 0  ;
	fscanf(fin , "%d%d%d" , &M , &S , &C);
	/*����ÿ��ţ�ı��*/
	for (i = 0;i < C;i ++){
		fscanf(fin , "%d" , &stall_num[i] );
	}
	
	qsort(stall_num , C , sizeof(int) , comp);//�ȶ��������� 
	
	/*�����ÿ�����ݼ�Ĳ�ֵ*/
	for( i = 0;i < C - 1;i ++ ){
		emp[i] = stall_num[i + 1] - stall_num[i] - 1;
	} 
	
	qsort(emp , C - 1 , sizeof(int) , comp);
	
	/*����ľ��������ţ����Ŀ����ֻ��ҪC��ľ��Ϳ�����*/
	if(M > C) result = C;
	else{
		
		result = stall_num[C - 1] - stall_num[0]  + 1 ;
	
		for(i = C - 2;i > C - 1 - M;i --) result -= emp[i];
	}
	fprintf( fout , "%d\n" , result );
	
	return 0;
}
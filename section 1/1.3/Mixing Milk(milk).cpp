/*ID:maosong1
LANG:C
PROB:milk
*/
#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b)//二维整数数组比较函数 
{
	return ((int *)a)[0] > ((int *)b)[0];
} 

int main()
{
	FILE *fin , *fout;
	fin = fopen( "milk.in" , "r" );
	fout = fopen( "milk.out" , "w" );
	
	long N , A[5005][2] , result = 0 , price_sum = 0;
	int M , i ;
	
	fscanf( fin,"%ld%d" , &N , &M );//输入需要牛奶重量N和奶农数M 
	
	/*输入每个奶农的价格和每天的供应量*/ 
	for( i = 0;i < M ;i ++){
		fscanf(fin , "%ld%ld" , &A[i][0] , &A[i][1]);
	} 
	
	qsort(A, M  ,sizeof(long)*2 , comp);//运用qsort对数据按价格进行排序 
	
	i = 0;
	while(1){
	    /*当已经超出要的总重量时*/
		if(result + A[i][1] >= N){
			price_sum += (N - result) * A[i][0];
			break;
		}
		/*其余情况，则继续对当前总重量和价格进行计算*/
		result += A[i][1];
		price_sum += A[i][1] * A[i][0];
		i ++;
	} 
	
	fprintf(fout , "%ld\n" , price_sum); 
	return 0;
}
/*ID:maosong1
LANG:C
PROB:milk
*/
#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b)//��ά��������ȽϺ��� 
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
	
	fscanf( fin,"%ld%d" , &N , &M );//������Ҫţ������N����ũ��M 
	
	/*����ÿ����ũ�ļ۸��ÿ��Ĺ�Ӧ��*/ 
	for( i = 0;i < M ;i ++){
		fscanf(fin , "%ld%ld" , &A[i][0] , &A[i][1]);
	} 
	
	qsort(A, M  ,sizeof(long)*2 , comp);//����qsort�����ݰ��۸�������� 
	
	i = 0;
	while(1){
	    /*���Ѿ�����Ҫ��������ʱ*/
		if(result + A[i][1] >= N){
			price_sum += (N - result) * A[i][0];
			break;
		}
		/*���������������Ե�ǰ�������ͼ۸���м���*/
		result += A[i][1];
		price_sum += A[i][1] * A[i][0];
		i ++;
	} 
	
	fprintf(fout , "%ld\n" , price_sum); 
	return 0;
}
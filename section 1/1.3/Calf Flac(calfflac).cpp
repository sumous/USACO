/*ID:maosong1
LANG:C
PROB:calfflac
*/
#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fin , *fout;
    fin = freopen( "calfflac.in" , "r" ,stdin );
    fout = freopen( "calfflac.out" , "w" , stdout);
    char a[20005] , temp[20005];
    int i , j , k , begin , stop , flag = 1,  count , max_count = 0;
    char pal[20005];
    while(  gets(temp) != NULL ){ //������������ʱ
         strcat(a , temp);
         a[strlen(a)] = '\n';
    }
        /* ���м俪ʼ���ң��ñ����ƽ⣬������ż*/

         for( i = 1;i < strlen(a) - 1;i ++ ){
              count = 1;
              /*������������������ĸ������ʱ  */
              k = i ;
              for( j = i - 1 ;j >= 0 ;j -- ){
                    if(!((a[j] >='A'&&a[j] <= 'Z')||(a[j] >= 'a'&&a[j] <= 'z')))
                        continue;
                        
                    for( k += 1;k < strlen(a) ;k ++ ){
                        if(!((a[k] >='A'&&a[k] <= 'Z')||(a[k] >='a'&&a[k] <= 'z')))
                            continue;
                            
                        /*������������ַ����������һ��ѭ��*/
                        if((a[j] == a[k])||((a[j] - 'A') == (a[k] - 'a'))||((a[j] - 'a') == (a[k] - 'A')))
                        {
                            count += 2;
                            flag  = 1;
                            /*��ס��������������ִ��Ŀ�ʼ����β�ͳ���*/
                            if(count > max_count){
                                max_count = count;
                                begin = j ;
                                stop = k ;
                               }
                            break;
                        }
                        else//����ȣ���˵���Ѿ��������м���Ϊi���������ִ���
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 0)  break;
              }

              
              /*ż�������*/
              k = i - 1;
              count = 0;
              for( j = i - 1;j >= 0 ;j -- ){
                   if(!((a[j] >='A'&&a[j] <= 'Z')||(a[j] >='a'&&a[j] <= 'z')))
                        continue;
                        
                   for( k += 1 ;k < strlen(a);k ++ ){
                        if(!((a[k] >='A'&&a[k] <= 'Z')||(a[k] >='a'&&a[k] <= 'z')))
                            continue;
                            
                        /*������������ַ����������һ��ѭ��*/
                        if((a[j] == a[k])||((a[j] - 'A') == (a[k] - 'a'))||((a[j] - 'a') == (a[k] - 'A')))
                        {
                            count += 2;
                            flag  = 1;
                            /*��ס��������������ִ��Ŀ�ʼ����β�ͳ���*/
                            if(count > max_count){
                                max_count = count;
                                begin = j;
                                stop = k;
                            }
                            break;
                        }
                        else//����ȣ���˵���Ѿ��������м���Ϊi���������ִ���
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 0)  break;
              }


              
         }


    /*�ҳ��������ִ��������Ƶ�pal������*/
         for ( i = begin  ,j = 0 ;i <= stop ;i ++,j ++){
              pal[j] = a[i];
         }
         pal[j] = '\0';
         //if(max_count == 777) max_count --;

         printf( "%d\n%d%s\n" , stop - begin ,max_count , pal ) ;

    return 0;
}

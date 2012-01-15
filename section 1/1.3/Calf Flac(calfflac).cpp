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
    while(  gets(temp) != NULL ){ //当输入了数据时
         strcat(a , temp);
         a[strlen(a)] = '\n';
    }
        /* 从中间开始查找，用暴力破解，但分奇偶*/

         for( i = 1;i < strlen(a) - 1;i ++ ){
              count = 1;
              /*奇数条件下满足是字母的条件时  */
              k = i ;
              for( j = i - 1 ;j >= 0 ;j -- ){
                    if(!((a[j] >='A'&&a[j] <= 'Z')||(a[j] >= 'a'&&a[j] <= 'z')))
                        continue;
                        
                    for( k += 1;k < strlen(a) ;k ++ ){
                        if(!((a[k] >='A'&&a[k] <= 'Z')||(a[k] >='a'&&a[k] <= 'z')))
                            continue;
                            
                        /*若是两个相等字符，则进入下一个循环*/
                        if((a[j] == a[k])||((a[j] - 'A') == (a[k] - 'a'))||((a[j] - 'a') == (a[k] - 'A')))
                        {
                            count += 2;
                            flag  = 1;
                            /*记住该情况下最大回文字串的开始、结尾和长度*/
                            if(count > max_count){
                                max_count = count;
                                begin = j ;
                                stop = k ;
                               }
                            break;
                        }
                        else//不相等，则说明已经超出了中间数为i的最大回文字串了
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 0)  break;
              }

              
              /*偶数情况下*/
              k = i - 1;
              count = 0;
              for( j = i - 1;j >= 0 ;j -- ){
                   if(!((a[j] >='A'&&a[j] <= 'Z')||(a[j] >='a'&&a[j] <= 'z')))
                        continue;
                        
                   for( k += 1 ;k < strlen(a);k ++ ){
                        if(!((a[k] >='A'&&a[k] <= 'Z')||(a[k] >='a'&&a[k] <= 'z')))
                            continue;
                            
                        /*若是两个相等字符，则进入下一个循环*/
                        if((a[j] == a[k])||((a[j] - 'A') == (a[k] - 'a'))||((a[j] - 'a') == (a[k] - 'A')))
                        {
                            count += 2;
                            flag  = 1;
                            /*记住该情况下最大回文字串的开始、结尾和长度*/
                            if(count > max_count){
                                max_count = count;
                                begin = j;
                                stop = k;
                            }
                            break;
                        }
                        else//不相等，则说明已经超出了中间数为i的最大回文字串了
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 0)  break;
              }


              
         }


    /*找出最大回文字串，并复制到pal数组中*/
         for ( i = begin  ,j = 0 ;i <= stop ;i ++,j ++){
              pal[j] = a[i];
         }
         pal[j] = '\0';
         //if(max_count == 777) max_count --;

         printf( "%d\n%d%s\n" , stop - begin ,max_count , pal ) ;

    return 0;
}

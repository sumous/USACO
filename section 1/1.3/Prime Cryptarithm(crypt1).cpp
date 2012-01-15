 /*ID:maosong1
LANG:C
PROB:crypt1
*/
 #include<stdio.h>
 #include<string.h>
int Judge(int *a , char *num , int n)//判断该情况是否为牛式
{
    int  flag = 0 , i , j;
    char test_ch[11];

    test_ch[6] = test_ch[0] = a[2] * a[4] % 10 + '0';

    test_ch[1] = (a[1] * a[4] +  a[2] * a[4] / 10) % 10+ '0';

    test_ch[2] = (a[1] * a[4] +  a[2] * a[4] / 10) / 10 + a[0] * a[4]+ '0';

    if(test_ch[2] - '0' >= 10) return 0;
    test_ch[3] =  a[2] * a[3] % 10+ '0';

    test_ch[4] = (a[1] * a[3] +  a[2] * a[3] / 10) % 10+ '0';
    test_ch[5] = (a[1] * a[3] +  a[2] * a[3] / 10) /10 + a[0] * a[3]+ '0';
    if(test_ch[5] - '0'>= 10) return 0;
    test_ch[7] = (test_ch[1] + test_ch[3] - '0' * 2) % 10+ '0';

    test_ch[8] =  ((test_ch[1] + test_ch[3] - '0' * 2) / 10 + test_ch[2] + test_ch[4] - '0' * 2) % 10+ '0';
    test_ch[9] =  ((test_ch[1] + test_ch[3] - '0' * 2) / 10 + test_ch[2] + test_ch[4] - '0' * 2) / 10 + test_ch[5] ;
    test_ch[10] = '\0';

    //printf("%s\n" , test_ch);
    if(test_ch[9] - '0'>= 10) return 0;

    for( i = 0;i < 10;i ++ ){

        if(strchr(num , test_ch[i])) {flag = 1 ;continue;}
        else return 0;

    }
     return flag;

}

 int main()
 {
    FILE *fin , *fout;
    fin = freopen("crypt1.in" , "r" , stdin);
    fout = freopen("crypt1.out" , "w" , stdout);
    int temp ,  n , i , j , k , v , w  , a[6];
    int count = 0 ;
    char num[10] ;
    scanf( "%d" , &n );
    
    /*输入数字*/
    getchar();
    for( i = 0; i < n - 1;i ++ ){
        num[i] = getchar();
        getchar();
    }
    num[n - 1] = getchar();
    num[n] = '\0';

    for( i = 0;i < n ;i ++ ){
         a[0] = num[i] - '0';
        for( j = 0;j < n;j ++ ){
            a[1] = num[j] - '0';
            for( k = 0;k < n;k ++ ){
                a[2] = num[k] - '0';
                for( v = 0;v < n;v ++ ){
                    a[3] = num[v] - '0';
                    for( w = 0;w < n;w ++ ){
                        a[4] = num[w] - '0';
                        /*粗略判断，用于剪枝*/   //  + a[1] * a[3] / 10     + a[1] * a[4] / 10
                        if((a[0] * a[3] > 10)||(a[4] * a[0]  > 10))
                            continue;
                        //if(a[0] != 3)
                        //printf( "%d %d %d %d %d\n" , a[0] , a[1],a[2],a[3],a[4] );
                        if(Judge(a , num , n)) count ++;
                    }
                }
            }
        }
    }
     printf( "%d\n" ,count );
    return 0;
 }

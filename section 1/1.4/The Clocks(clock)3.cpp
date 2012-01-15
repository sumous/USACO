/*ID:maosong1
LANG:C
PROB:clocks
*/
#include<stdio.h>
#include<math.h>
/**
**�����Ǳ任���������� 
**/
int a[9][9]= { {3,3,3,3,3,2,3,2,0},
               {2,3,2,3,2,3,1,0,1},
               {3,3,3,2,3,3,0,2,3},
               {2,3,1,3,2,0,2,3,1},
               {2,3,2,3,1,3,2,3,2},
               {1,3,2,0,2,3,1,3,2},
               {3,2,0,3,3,2,3,3,3},
               {1,0,1,3,2,3,2,3,2},
               {0,2,3,2,3,3,3,3,3} };
int v[9];
 
int main() {
    int i,j,k;
    freopen("clocks.in","r",stdin);
    for (i=0; i<9; i++) {
        scanf("%d",&k);
        for(j=0; j<9; j++)
             v[j]=(v[j]+(4-k/3)*a[i][j])%4;
    }
    fclose(stdin);
 
    k=0;
    freopen("clocks.out","w",stdout);
    for (i=0; i<9; i++)
        for (j=0; j<v[i]; j++)
            if (!k) { printf("%d",i+1); k=1; }
            else    printf(" %d",i+1);
    printf("\n");
    fclose(stdout);
    return 0;
}
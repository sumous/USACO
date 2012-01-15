/*
ID: maosong1
LANG: C
TASK: ride
*/

#include <stdio.h>
int main(){
    FILE *fin =fopen("ride.in", "r");
    FILE *fout=fopen("ride.out", "w");
 
    char a[7],b[7];                 
    long i,ca=1,cb=1;              
 
    fscanf (fin, "%s %s",a,b);
 
    for (i=0;a[i];i++)
        ca*=a[i]-64;
    for (i=0;b[i];i++)
        cb*=b[i]-64;
 
    if (ca%47==cb%47)fprintf(fout,"GO\n");
    else fprintf(fout,"STAY\n");
 
    exit (0);
}
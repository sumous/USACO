#include <iostream>
int main()
{
    int a = 0;
    if(a == 0)
    {
    #define m 1
    }
    else
{
    #define m 3
}
    #if m==1
    cout<<"hllo"
    #else
    cout<<"no"
    #endif
    return 0;
}

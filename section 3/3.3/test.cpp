#include <iostream>
using namespace std;

class test
{
    public:
        int a;
    void show()
    {
        cout<<a;
    }
};


class test1:public test
{
    void fun2()
    {
cout<<a;
    }
};
void operator << ()
{
    cout<<"hello";
}


int main()
{

  cout<<3;
    return 0;
}

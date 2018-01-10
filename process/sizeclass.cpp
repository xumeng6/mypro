#include <iostream>
using namespace std;
class A
{
    char k[3];
    public:
    virtual void aa(){};
};
class B
{
    char q[3];
    public:
    virtual void bb();
};
class C: public A,public B
{
    char j[3];
    public:
    virtual void cc(){};
};
int main()
{
    cout<<"sizeof(A):"<<sizeof(A)<<endl;
    cout<<"sizeof(B):"<<sizeof(B)<<endl;
    cout<<"sizeof(C):"<<sizeof(C)<<endl;
    return 0;
}

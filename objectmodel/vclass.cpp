#include<iostream>
using namespace::std;
class a{
	int a;
	virtual void func();
};
class b:virtual public a{
	virtual void foo();
};
class c:public a{
	virtual void fu();
};
int main()
{
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;	
	cout<<sizeof(c)<<endl;
	return 0;
}

#include<iostream>
using namespace std;
class B{};
class B1:virtual public B{};
class B2:virtual public B{};
class C:public B1,public B2{};
int main(){
	B b;
	B1 b1;
	B2 b2;
	C c;
	int *p;
	long a=1;
	cout<<sizeof(b)<<endl;
	cout<<sizeof(b1)<<endl;
	cout<<sizeof(b2)<<endl;
	cout<<sizeof(c)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(p)<<endl;
	return 0;
}


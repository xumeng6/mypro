#include <iostream>
using namespace::std;

#include "car.h"
void foo(Car *pcar)
{
	pcar->print();
	pcar->stop();
}
void bar(Car& rcar)
{
	rcar.print();
	rcar.stop();
}
int main()
{
	Car a;
	cout<< sizeof(a)<<endl;
	cout<< "The address of a is "<<& a<<endl;
	a.setProperty(10000,10001);
	a.run();
	a.stop();
	a.print();
	foo(&a);
	bar(a);
	return 0;
}

#include<iostream>
#include<unistd.h>
using namespace::std;
int main()
{
	cout<<getpid()<<endl;
	sleep(1);
	return 99;
}

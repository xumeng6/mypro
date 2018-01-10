#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<sys/wait.h>
using namespace::std;
int main()
{
       int r=system("./test");
//	cout<<fp<<endl;
	cout<<getpid()<<endl;
	cout<<r<<endl;
	cout<<WEXITSTATUS(r)<<endl;
	return 0;
}

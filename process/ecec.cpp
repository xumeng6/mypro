#include<iostream>
#include<unistd.h>
int main()
{
	int r =execlp("ls","ls",NULL);
	std::cout<<r<<std::endl;
	return 0;
}

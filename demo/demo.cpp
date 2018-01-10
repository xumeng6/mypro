#include <iostream>
int inputInt();
int isPrimer(int a);
int main()
{
	int a=inputInt();
	int r=isPrimer(a);
	if(r==1)
	{
			std::cout<<"it is aprime:"<<a<<std::endl;
	}
	else
	{
			std::cout<<"it is not a prime:"<<a<<std::endl;
	}
	return 0;
}

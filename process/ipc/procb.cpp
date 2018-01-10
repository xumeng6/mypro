#include<iostream>
#include<sys/mman.h>
#include<fcntl.h>
using namespace::std;
int main()
{
	int fd=open("tmp",O_RDWR);
	int *p=(int *)mmap(0,4,PROT_READ|PROT_WRITE,
	MAP_SHARED,fd,0);
	while(1)
	{
		sleep(1);
		cout<<*p<<endl;
		
	}
	close(fd);
}

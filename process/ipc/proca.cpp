#include<iostream>
#include<sys/mman.h>
//#include<cstdio>
#include<fcntl.h>
using namespace::std;
int main()
{
	int i=0;
	int fd=open("tmp",O_RDWR|O_CREAT,0666);
	ftruncate(fd,4);//xianding4gezijie
        int *p=(int*)mmap(0,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	while(1)
	{
		sleep(1);
		*p=i;
		++i;
	}
	close(fd);
}

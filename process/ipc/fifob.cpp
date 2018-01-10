#include<iostream>
#include<sys/stat.h>
#include<signal.h>
#include<fcntl.h>
#include<cstdlib>
using namespace::std;
int fd;
void end(int s)
{	
	close(fd);
	exit(-1);
}
int main()
{
	int i;
	signal(SIGINT,end);
	fd=open("my.pipe",O_RDWR);
	while(1)
	{
		read(fd,&i,4);
		cout<<i<<endl;
	}	
}

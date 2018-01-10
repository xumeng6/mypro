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
	unlink("my.pipe");
	exit(-1);
}
int main()
{
	int i;
	mkfifo("my.pipe",0666);
	signal(SIGINT,end);
	fd=open("my.pipe",O_RDWR);
	while(1)
	{
		sleep(1);
		write(fd,&i,4);
		++i;
	}	
}

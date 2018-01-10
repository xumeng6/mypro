#include<iostream>
#include<sys/poll.h>
#include<unistd.h>
int main()
{
	struct pollfd fds[1];
	char buf[100];
	int r;
	fds[0].fd=0;
	fds[0].events=POLLIN;
	while(1)
	{
		r=poll(fds,1,-1);
		if(fds[0].revents&POLLIN)
		{
			std::cout<<"data"<<std::endl;
			r=read(0,buf,99);
		}
	}
}

#include<iostream>
#include<unistd.h>
using namespace::std;
int main()
{
	int fd[2];
	pipe(fd);
	if(fork())
	{
		close(fd[0]);
		while(1)
		{
			write(fd[1],"hello",5);
			sleep(1);
		}
	}else
	{
		close(fd[1]);
		char buf[6];
		while(1)
		{
			read(fd[0],buf,6);
			cout<<buf<<endl;

		}

	}	

}

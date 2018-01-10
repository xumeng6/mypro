#include<iostream>
using namespace::std;
int main()
{
	int fd[2];
	int r;
	char buf[20];
	cout<<getpid()<<endl;
	r=pipe(fd);
	cout<<r<<endl;
	write(fd[1],"hello",5);
	write(fd[1],"world",5);
	r=read(fd[0],buf,20);
	buf[r]=0;
	cout<<r<<endl;
	cout<<buf<<endl;
	write(fd[1],"louis",5);
	r=read(fd[0],buf,20);
	buf[r]=0;
	cout<<r<<endl;
	cout<<buf<<endl;
	while(1);

}

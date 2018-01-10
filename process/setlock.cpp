#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
using namespace::std;
int main()
{
	int fd,r;
	struct flock lk;
	fd=open("a.txt",O_RDWR);
	if(fd==-1) 
		cout<<"123124"<<endl;
	lk.l_type=F_WRLCK;
	lk.l_whence=SEEK_SET;
	lk.l_start=5;
	lk.l_len=10;
	r=fcntl(fd,F_SETLK,&lk);
	if(r==0)
		cout<<"success"<<endl;
	else
		cout<<"failed"<<endl;
	while(1);
	return 0;
}

#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace::std;
int main()
{
	int fd;
	int type;
	int len;
	len=sizeof(type);
	fd=socket(AF_INET,SOCK_STREAM,0);
	getsockopt(fd,SOL_SOCKET,SO_TYPE,&type,(socklen_t*)&len);
	cout<<SOCK_STREAM<<SOCK_DGRAM<<type<<endl;
	if(type&SOCK_STREAM)
	{
		cout<<"liu"<<endl;
	}
	if(type&SOCK_DGRAM)
	{
		cout<<"baowen"<<endl;
	}
	getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&type,(socklen_t*)&len);
	cout<<type<<endl;
}

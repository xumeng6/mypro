#include<iostream>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<cstring>
#include<netinet/in.h>
#include<unistd.h>
using namespace::std;

int main()
{
	int fd;
	int r;
	char buf[100];
	struct sockaddr_in addr;
	socklen_t len;
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		cout<<"buildsock erro"<<endl;
		return -1;
	} 
	cout<<"buildsock success"<<endl;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(9999);
	inet_aton("127.0.0.1",&addr.sin_addr);
	r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1)
	{
		cout<<"connection error"<<endl;
		return -2;
	} 
	cout<<"connection success"<<endl;
	for(int i=0;i<20;++i)
	{
		send(fd,"hello",5,0);
	}
	return 0;
}

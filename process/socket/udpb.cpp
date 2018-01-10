#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<arpa/inet.h>
int main()
{
	int fd;
	struct sockaddr_in ad;
	char buf[101];
	int r;
	fd=socket(AF_INET,SOCK_DGRAM,17);
	if(fd==-1)
	{
		std::cout<<"bulid error"<<std::endl;
		return -1;
	}
	std::cout<<"build success"<<std::endl;
	ad.sin_family=AF_INET;
	ad.sin_port=htons(11111);
	ad.sin_addr.s_addr=inet_addr("127.0.0.1");	
	while(1)
	{
		r=read(0,buf,sizeof(buf)-1);
		if(r<=0)
			break;
		buf[r]='\0';
		r=sendto(fd,buf,r,0,(struct sockaddr*)&ad,sizeof(ad));
		bzero(buf,sizeof(buf));
		r=recv(fd,buf,sizeof(buf),0);
		buf[r]='\0';
		std::cout<<buf<<std::endl;
		if(r==-1)
			break;
	}
	close(fd);
	return 0;
}

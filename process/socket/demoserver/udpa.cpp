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
	char buf[100];
	struct sockaddr_in ad_snd;
	int r;
	socklen_t len;//the length of sender
	fd=socket(AF_INET,SOCK_DGRAM,17);
	if(fd==-1)
	{
		std::cout<<"bulid error"<<std::endl;
		return -1;
	}
	std::cout<<"build success"<<std::endl;
	ad.sin_family=AF_INET;
	ad.sin_port=htons(11111);	
	inet_aton("127.0.0.0.1",&ad.sin_addr);
	r=bind(fd,(struct sockaddr*)&ad,sizeof(ad));	
	if(r==-1)
	{
		std::cout<<"bind error"<<std::endl;
		return -1;
	}
	std::cout<<"bind success"<<std::endl;
	while(1)
	{
		len=sizeof(ad_snd);
		r=recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&ad_snd,&len);
		if(r>0)
		{	
			buf[r]=0;
			std::cout<<"the ip of sender"<<inet_ntoa(ad_snd.sin_addr)
			<<" the port is: "<<ntohs(ad_snd.sin_port)<<"the data is:"<<buf<<std::endl;
			sendto(fd,"i have receive this message!",30,0,(struct sockaddr*)&ad_snd,len);
		}
		if(r==0)
		{
			std::cout<<"close"<<std::endl;
			break;
		}
		if(r==-1)
		{
			std::cout<<"internet fault"<<std::endl;
			break;	
		}
	}
	close(fd);
	return 0;
}

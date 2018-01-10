#include<iostream>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<cstring>
#include<netinet/in.h>
#include<unistd.h>
using namespace::std;

int main()
{
	int serverfd;
	int cfd;
	int r;
	char buf[1000];
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;
	socklen_t len;
	serverfd=socket(AF_INET,SOCK_STREAM,0);
	if(serverfd==-1)
	{
		cout<<"buildsock erro"<<endl;
		return -1;
	} 
	cout<<"buildsock success"<<endl;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(9999);
	inet_aton("127.0.0.1",&saddr.sin_addr);
	r=bind(serverfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(r==-1)
	{
		cout<<"bind error"<<endl;
		return -2;
	} 
	cout<<"bind success"<<endl;
	
	//listen
	r=listen(serverfd,10);
	if(r==-1)
	{
		cout<<"listen error"<<endl;
		return -3;
	} 
	cout<<"listen success"<<endl;

	//accept
//	while(1)
//	{
	len=sizeof(caddr);
	cfd=accept(serverfd,(struct sockaddr*)&caddr,&len);
	cout<<"cfd::"<<cfd<<" ip:"<<inet_ntoa(caddr.sin_addr)<<" port:"
		<<ntohs(caddr.sin_port)<<endl;
//	}
	while(1)
	{		
	r=recv(cfd,buf,1000,MSG_WAITALL);
	if(r>0)
	{
		buf[r]='\0';
		cout<<"::"<<buf<<endl;
	}	
	if(r==0)
	{
		cout<<"connection break "<<endl;
		break;
	}
	if(r==-1)
	{
		cout<<"internet fault"<<endl;
		break;
	}
	}
	return 0;
}

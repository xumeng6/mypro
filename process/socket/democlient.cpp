#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<cstring>
using namespace::std;
int main()
{
	int sfd;
	int ffd;
	struct sockaddr_in addr;
	int r;
	int len;
	int size;
	char buf[100];	
	char filename[]="udpa.cpp";
	sfd=socket(AF_INET,SOCK_STREAM,6);
	if(sfd==-1)
	{
		cout<<"build error"<<endl;
		return -1;
	}
	cout<<"build success!"<<endl;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	inet_aton("127.0.0.1",&addr.sin_addr);	
	//addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=connect(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1)
	{
		cout<<"connection error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"connection success!"<<endl;
	ffd=open(filename,O_RDONLY);	
	if(ffd==-1)
	{
		cout<<"openfile error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"openfile success!"<<endl;
	len=strlen(filename);
	r=send(sfd,&len,sizeof(len),0);
	r=send(sfd,filename,len,0);
	if(r==-1)
	{
		cout<<"sendfilename error"<<endl;
		close(ffd);
		close(sfd);
		return -1;
	}
	cout<<"sendfilename success!"<<endl;
	while(1)
	{
		size=read(ffd,buf,100);
		if(size==-1) break;
		if(size==0)  break;
		if(size>0)
		{
			r=send(sfd,&size,sizeof(size),0);
			if(r==-1)	break;
			r=send(sfd,buf,size,0);
			if(r==-1)	break;
		}
	}
	size=0;
	r=send(sfd,&size,sizeof(size),0);
	close(ffd);
	close(sfd);
	cout<<"send completion"<<endl;
	return 0;
}

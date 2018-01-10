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
	int sfd,ffd,cfd;
	struct sockaddr_in addr;
	int r;
	int len;
	char buf[100];	
	char filename[100];
	sfd=socket(AF_INET,SOCK_STREAM,6);
	if(sfd==-1)
	{
		cout<<"build error"<<endl;
		return -1;
	}
	cout<<"build success!"<<endl;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(8888);
	//inet_aton("127.0.0.1",&addr.sin_addr);	
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
	if(r==-1)
	{
		cout<<"bind error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"bind success!"<<endl;
	r=listen(sfd,10);
	if(r==-1)
	{
		cout<<"listen error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"listen success!"<<endl;

	cfd=accept(sfd,0,0);
	if(cfd==-1)
	{
		cout<<"accept error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"start accept file"<<endl;
	r=recv(cfd,&len,sizeof(len),MSG_WAITALL);
	r=recv(cfd,filename,len,MSG_WAITALL);
	filename[len]='\0';
	cout<<"the filename that server receives is: "<<filename<<endl;
	ffd=open(filename,O_RDWR|O_CREAT,0666);
	if(ffd==-1)
	{
		cout<<"creatfile error"<<endl;
		close(sfd);
		return -1;
	}
	cout<<"creatfile success!"<<endl;

	while(1)
	{
		r=recv(cfd,&len,sizeof(len),MSG_WAITALL);
		if(len==0) break;
		r=recv(cfd,buf,len,MSG_WAITALL);
		write(ffd,buf,len);
	}
	close(ffd);
	close(cfd);
	close(sfd);
	cout<<"recv completion"<<endl;
	return 0;
}

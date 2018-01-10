#include<iostream>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<cstring>
#include<cstdio>
#include<signal.h>
#include<cstdlib>
using namespace::std;
int msgid;
key_t key;
int i;
struct mybuf
{
	long mtype;
	char mtext[32];
};
void deal(int s)
{
	if(s==SIGINT)
	{
		msgctl(msgid,IPC_RMID,0);
		exit(1);	
	}

}
int main()
{
	signal(SIGINT,deal);
	key=ftok(".",200);
	if(key==-1)
		cout<<"ftok error!"<<endl;
	msgid=msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(msgid==-1)
		cout<<"get error"<<endl;
	struct mybuf msg;
	for(i=1;i<=10;i++)
	{
		bzero(msg.mtext,sizeof(msg.mtext));
		msg.mtype=2;
		sprintf(msg.mtext,"message:%d",i);
		msgsnd(msgid,&msg,sizeof(msg.mtext),0);
		cout<<msgid<<endl;
	}
	while(1);

}

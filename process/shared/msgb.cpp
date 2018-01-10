#include<iostream>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<cstring>
#include<cstdio>
using namespace::std;
key_t key;
int msgid;
struct mybuf
{
	long type;
	char s[32];
};
int main()
{
	struct mybuf msg;
	key=ftok(".",200);
	if(key==-1)
		cout<<"ftok error!"<<endl;
	msgid=msgget(key,0);
	if(msgid==-1)
		cout<<"get error"<<endl;
	bzero(&msg,sizeof(msg));
	while(1)
	{
		msgrcv(msgid,&msg,sizeof(msg),2,0);
		cout<<msg.s<<endl;
	}

}

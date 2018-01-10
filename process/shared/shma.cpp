#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<cstdlib>
#include<signal.h>
using namespace::std;
int *p;	
key_t key;
int shmid;
int i=0;
void handle(int s)
{
	if(s==SIGINT)
	{
		shmdt(p);
		shmctl(shmid,IPC_RMID,0);
		exit(0);
	}
}

int main()
{
	signal(SIGINT,handle);
	key=ftok(".",255);
	shmid=shmget(key,4,IPC_CREAT|IPC_EXCL|0666);
	if(shmid==-1)
		cout<<"error:"<<endl;
	p=(int *)shmat(shmid,0,0);
	if(p==(int *)-1)
		cout<<"at error"<<endl;
	while(1)
	{
		*p=i;
		sleep(1);
		++i;
	}
}

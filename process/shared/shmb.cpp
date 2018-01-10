#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<cstdlib>
#include<signal.h>
using namespace::std;
int *p;	
key_t key1;
int shmid1;
void handle(int s)
{
	if(s==SIGINT)
	{
		shmdt(p);
		exit(0);
	}
}

int main()
{
	signal(SIGINT,handle);
	key1=ftok(".",255);
	shmid1=shmget(key1,4,0);
	p=(int *)shmat(shmid1,0,0);
	if(p==(int *)-1)
		cout<<"at error"<<endl;
	while(1)
	{
		sleep(1);
		cout<<*p<<endl;
	}
}

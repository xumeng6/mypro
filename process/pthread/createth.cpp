#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<sched.h>
using namespace::std;
void* run_thread(void *)
{
	while(1)
	{
	cout<<"i am thread"<<endl;
	sched_yield();
	}
}
void* run_thread2(void *)
{
	while(1)
	{
	cout<<"i am thread22"<<endl;
	sched_yield();
	}
}
int main()
{
	pthread_t tid,tid2;
	pthread_create(&tid,0,run_thread,0);
	pthread_create(&tid2,0,run_thread2,0);
	while(1)
	{
		cout<<"i am the main thread"<<endl;
		sched_yield();
	}
	pthread_join(tid,(void**)0);
	pthread_join(tid2,(void**)0);
	return 0;
}

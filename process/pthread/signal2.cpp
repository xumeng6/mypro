#include<iostream>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
using namespace::std;
pthread_t a,b;
sigset_t sigs;
void *funa(void*)
{
	int s;
	while(1)
	{
		sigwait(&sigs,&s);
		cout<<"adadada"<<endl;
	}
}
void* funb(void*)
{
	while(1)
	{
		sleep(1);
		pthread_kill(a,34);
	}

}
int main()
{
	sigemptyset(&sigs);
	sigaddset(&sigs,34);
	sigprocmask(SIG_BLOCK,&sigs,0);
	pthread_create(&a,0,funa,0);
	pthread_create(&b,0,funb,0);
	pthread_join(a,(void**)0);
	pthread_join(b,(void**)0);
	return 0;
}

#include<iostream>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
using namespace::std;
pthread_t odd,even;
sigset_t sigs;
void* oddfun(void*)
{
	int i;
	int s;
	for(i=1;;i+=2)
	{
		cout<<i<<endl;
		sigwait(&sigs,&s);
	}
}
void* evenfun(void *)
{
	int i;
	for(i=0;;i+=2)
	{
		cout<<i<<endl;
		sleep(1);
		pthread_kill(odd,34);
	}
}
int main()
{
	sigemptyset(&sigs);
	sigaddset(&sigs,34);
	sigprocmask(SIG_BLOCK,&sigs,0);
	pthread_create(&odd,0,oddfun,0);
	pthread_create(&even,0,evenfun,0);
	pthread_join(odd,(void**)0);
	pthread_join(even,(void**)0);
	return 0;
}

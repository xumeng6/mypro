#include<iostream>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
using namespace::std;
pthread_t a,b;
pthread_cond_t cond;
pthread_mutex_t m;
void *funa(void*)
{
	while(1)
	{
		pthread_cond_wait(&cond,&m);
		cout<<"adadada"<<endl;
	}
}
void* funb(void*)
{
	while(1)
	{
//		sleep(1);
		pthread_cond_signal(&cond);
	}

}
int main()
{
	pthread_mutex_init(&m,0);
	pthread_cond_init(&cond,0);
	pthread_create(&a,0,funa,0);
	pthread_create(&b,0,funb,0);
	pthread_join(a,(void**)0);
	pthread_join(b,(void**)0);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&m);
	return 0;
}

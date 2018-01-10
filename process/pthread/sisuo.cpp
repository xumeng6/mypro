#include<iostream>
#include<pthread.h>
using namespace::std;
pthread_mutex_t m;
void handle(void*)
{
	cout<<"the fun of unormal quit"<<endl;
	pthread_mutex_unlock(&m);
}
void* oddfun(void*)
{
	int i;
	for(i=1;;i+=2)
	{
		pthread_cleanup_push(handle,0);
		pthread_mutex_lock(&m);
		cout<<i<<endl;
		if(i>10000)
		{
			pthread_exit((int *)1);
		}
		pthread_mutex_unlock(&m);
		pthread_cleanup_pop(0);
	}
}
void* evenfun(void*)
{
	int i;
	for(i=0;;i+=2)
	{
		pthread_cleanup_push(handle,0);
		pthread_mutex_lock(&m);
		cout<<i<<endl;
		pthread_mutex_unlock(&m);
		pthread_cleanup_pop(0);
	}
}
int main()
{
	pthread_t odd,even;
	pthread_mutex_init(&m,0);
	pthread_create(&odd,0,oddfun,0);
	pthread_create(&even,0,evenfun,0);
	pthread_join(odd,(void**)0);
	pthread_join(even,(void**)0);
	pthread_mutex_destroy(&m);
	return 0;
}

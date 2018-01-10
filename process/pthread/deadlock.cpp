#include<iostream>
#include<pthread.h>
using namespace::std;
pthread_t t1,t2;
pthread_mutex_t m1,m2;
pthread_cond_t cond;
void* funt1(void*)
{
	while(1)
	{
		pthread_mutex_lock(&m1);
		cout<<"i am waiting"<<endl;
		pthread_cond_wait(&cond,&m1);
		pthread_mutex_unlock(&m1);
	}

}
void* funt2(void*)
{
	while(1)
	{
		pthread_mutex_lock(&m1);
		pthread_cond_signal(&cond);
		cout<<"i am sending signal"<<endl;
		pthread_mutex_unlock(&m1);
	}
}
int main()
{
	pthread_mutex_init(&m1,0);
	pthread_mutex_init(&m2,0);
	pthread_cond_init(&cond,0);

	pthread_create(&t1,0,funt1,0);
	pthread_create(&t2,0,funt2,0);
	pthread_join(t1,(void**)0);
	pthread_join(t2,(void**)0);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&m2);
	pthread_mutex_destroy(&m1);
	return 0;

}



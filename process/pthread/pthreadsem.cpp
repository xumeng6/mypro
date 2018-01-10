#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace::std;
pthread_t t1;
sem_t sem;
void* funt1(void*)
{
	while(1)
	{
		sem_wait(&sem);
		cout<<"release plug"<<endl;
	}

}
int main()
{
	sem_init(&sem,0,5);
	pthread_create(&t1,0,funt1,0);
//	pthread_join(t1,(void**)0);
	sem_destroy(&sem);
	while(1)
	{
		sleep(1);
		sem_post(&sem);
	}
	return 0;
}

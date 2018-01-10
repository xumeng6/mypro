#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace::std;

void* run_thread(void *data)
{
	while(1)
	{
		cout<<"i am thread"<<(char *)data<<endl;
		pthread_exit((void*)"hello");
	}
}
int main()
{
	pthread_t tid;
	char *bud;
	char buf[]="dsss";
	pthread_create(&tid,0,run_thread,buf);
	cout<<"i am the main thread"<<endl;
	pthread_join(tid,(void**)&bud);
	cout<<bud<<endl;
	return 0;
}

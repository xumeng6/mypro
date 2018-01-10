#include<iostream>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<cmath>
#include<fstream>
using namespace::std;
pthread_t pri1,pri2,txt;
pthread_cond_t cond;
pthread_mutex_t m;
int buf[5001];
int num=0;
void* prifun1(void*)
{
	int j;
	pthread_mutex_lock(&m);
	for(int i=2;i<=2500;i++)
	{
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0) break;
		}
		if(j>sqrt(i))
		{
			buf[num++]=i;
			cout<<i<<endl;
		}
	}
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&m);
}
void* prifun2(void*)
{
	int j;
	pthread_mutex_lock(&m);
	for(int i=2501;i<=5000;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0) break;
		}
		if(j>sqrt(i))
		{
			buf[num++]=i;
			cout<<i<<endl;
		}
	}
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&m);
}
void* txtfun(void*)
{
	pthread_mutex_lock(&m);
	pthread_cond_wait(&cond,&m);
	fstream in("2.txt",ios::out|ios::app);
	for(int i=0;i<=num;i++)
	{
		in<<buf[i]<<endl;
	}
	in.close();
	pthread_mutex_unlock(&m);

}
int main()
{
	pthread_mutex_init(&m,0);
	pthread_cond_init(&cond,0);

	pthread_create(&pri1,0,prifun1,0);
	pthread_create(&pri2,0,prifun2,0);
	pthread_create(&txt,0,txtfun,0);

	pthread_join(pri1,(void**)0);
	pthread_join(pri2,(void**)0);
	pthread_join(pri1,(void**)0);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&m);
	return 0;
}


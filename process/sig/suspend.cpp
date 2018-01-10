#include<iostream>
#include<signal.h>
using namespace::std;

void handle(int s)
{
	cout<<"the pid is:"<<s<<endl;
}
int main()
{
	int sum=0;
	sigset_t sigs,sigt;
	sigemptyset(&sigs);
	sigemptyset(&sigt);
	sigaddset(&sigs,SIGINT);

	signal(SIGINT,handle);	

	sigprocmask(SIG_BLOCK,&sigs,0);
	for(int i=0;i<10;i++)
	{
		++sum;
//		sleep(1);
		sigsuspend(&sigt);
//		sleep(1);
	} 
	cout<<"over"<<sum<<endl;
	sigprocmask(SIG_UNBLOCK,&sigs,0);
	return 0;
}

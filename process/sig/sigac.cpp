#include<iostream>
#include<signal.h>
using namespace::std;
void handle(int s)
{
	cout<<"ok!!!"<<endl;
	sleep(5);
	cout<<"ok2222!!!"<<endl;
}
int main()
{
	struct sigaction act={0};
	act.sa_handler=handle;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGINT);
	act.sa_flags=0;

	sigaction(SIGUSR1,&act,0);
	while(1);
}

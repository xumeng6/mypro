#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace::std;
void handle(int s)
{
	cout<<"i am a signal"<<endl;
	sleep(5);
}
int main()
{
	signal(SIGINT,handle);
	while(1)
	{
		cout<<"zhengzaiyunxing"<<endl;
		sleep(1);
	}
	return 0;
}

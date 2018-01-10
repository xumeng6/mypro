#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
using namespace::std;

void deal(int s)
{
	int sta;
	wait(&sta);
	cout<<WEXITSTATUS(sta)<<endl;
}
int main()
{
	if(!fork())
	{
		cout<<"child"<<endl;
		sleep(10);
		cout<<"exit!!"<<endl;
		exit(88);
	}else
	{
		signal(SIGCHLD,deal);
		while(1)
		{
			cout<<"parent"<<endl;
			sleep(1);
		}
	}
	return 0;
}

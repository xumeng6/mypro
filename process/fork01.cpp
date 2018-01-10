#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	cout<<"chuanjianqian"<<endl;
	int pid=fork();
	while(1)
       {
	if(pid==0)
	{
	cout<<getpid()<<endl;
	cout<<"after::"<<pid<<endl;
	sleep(1);
	}else
	{
	cout<<getpid()<<endl;
	cout<<"after::"<<pid<<endl;
	sleep(1);
	}
	}
	return 0;
}

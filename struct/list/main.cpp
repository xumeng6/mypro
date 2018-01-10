#include"list.h"
#include<iostream>
using namespace::std;
int main()
{
//	time t;
	List l;
//	cout<<l.front()<<endl;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.push_front(5);
	l.push_front(5);
	l.push_front(5);
	l.push_front(5);
	l.insert(6,2);
	l.travel();
	l.erase(3);
	l.travel();
	l.set(l.find(5),7);
	l.travel();
	l.remove(7);
	l.travel();
	l.set(0,2);
	l.travel();
	cout<<l.front()<<l.back()<<endl;
        char n='a';
	int a,b;	
	while(n!='q')
	{
	cin>>n;
	if(n=='i' ){
		cin>>a>>b;
		l.insert(a,b);
		l.travel();
	}
	else if(n=='f'){
		cin>>a;
		l.push_front(a);
		l.travel();
	}
	}
	l.inversion();
	l.travel();
//	cout<<"now:"<<t.elapsed()<<"s"<<endl;
	return 0;
}

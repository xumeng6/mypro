#include<iostream>
#include<string>
using namespace::std;
typedef string T;
class Stack{
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*);
	T pop()throw(const char*);
	const T& top()const throw(const char*);
	bool empty() const{return cur==0;}
	bool full() const{return cur==5;}
	void clear(){ cur=0;}
	int size()const{return cur;}
private:
	T a[5];
	int cur;
};	
void Stack::push(const T& d)throw(const char*)
{
	if(full()) 
		throw "full";
	a[cur++]=d;
}
T Stack::pop()throw(const char*)
{
	if(empty())
		throw "empty";
	return a[--cur];
}
const T& Stack::top()const throw(const char*)
{
	if(empty())
		throw "empty";
		return a[cur-1];
}
int main()
{
	Stack s;
	try
	{
	s.push("zenge");
	s.push("权哥");
	s.push("furong");
	s.push("zege");
	s.push("ze33nge");
	s.push("333333");
	s.push("sfs");
	}
	catch(const char* e)
	{
		cout<<"yichang"<<' '<<e<<endl;
	}	
	while(!s.empty())
	{
		cout<<s.pop()<<endl;
	}
}

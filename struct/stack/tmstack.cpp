#include<iostream>
#include<string>
#include<typeinfo>
using namespace::std;
template<typename T=int, int len=10>
class Stack{
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*);
	T pop()throw(const char*);
	const T& top()const throw(const char*);
	bool empty() const{return cur==0;}
	bool full() const{return cur==len;}
	void clear(){ cur=0;}
	int size()const{return cur;}
	const char* element()const
	{
		return typeid(T).name();
	}
	int max_size()const
	{
		return len;
	}
private:
	T a[len];
	int cur;
};	
template<typename T,int len>
void Stack<T,len>::push(const T& d)throw(const char*)
{
	if(full()) 
		throw "full";
	a[cur++]=d;
}
template<typename T,int len>
T Stack<T,len>::pop()throw(const char*)
{
	if(empty())
		throw "empty";
	return a[--cur];
}
template<typename T,int len>
const T& Stack<T,len>::top()const throw(const char*)
{
	if(empty())
		throw "empty";
		return a[cur-1];
}
int main()
{
	Stack<char,30> s;
	Stack<double,20> d;
	Stack<float> a;
	Stack<> n;
	cout<<typeid(s).name()<<'\t'<<typeid(d).name()<<endl;
	cout<<s.element()<<':'<<s.max_size()<<endl;
	cout<<d.element()<<':'<<d.max_size()<<endl;
	cout<<a.element()<<':'<<a.max_size()<<endl;
	cout<<n.element()<<':'<<n.max_size()<<endl;
}
	


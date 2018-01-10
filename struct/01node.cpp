#include <iostream>

using namespace::std;
typedef int T;
struct Node{
	T data;
	Node *next;
	Node(const T& d):data(d),next(NULL){}
	operator T()
	{return data;}

};
void showlist(Node* head)
{
	Node* p=head;
	while(p!=NULL)
	{
		cout<<*p<<' ';
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	Node a(10),b(20),c(30),d(40),f(50),e(60);
	a.next=&b;
	b.next=&c;
	c.next=&d;
	showlist(&a);
	Node* &p=b.next;
	e.next=p;
	p=&e;	
	showlist(&a);
	return 0;
}

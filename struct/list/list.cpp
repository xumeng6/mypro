#include<iostream>
#include "list.h"
using namespace::std;
void List::push_front(const T& d){
	insert(d,0);
}
List& List::push_back(const T& d){
	insert(d,size());
	return *this;
}
int List::size()const{
	return len;
}
List::Node* & List::getptr(int pos){
	if(pos<0||pos>size())
		pos=0;
	if(pos==0) 
		return head;
	Node* p=head;
	for(int i=1;i<pos;i++)
		p=p->next;
	return p->next;
}
void List::insert(const T&d,int pos)
{
	Node* &pn=getptr(pos);
	Node* a=new Node(d);
	a->next=pn;
	pn=a;
	++len;
}
void List::travel()const
{
	Node* p=head;
	while(p!=NULL)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
void List::clear()
{
	while(head!=NULL)
	{
		Node* p=head->next;
		delete head;
		head=p;
	}
	len=0;
}
List::~List()
{
	clear();
}
void List::erase(int pos)
{
 	if(pos<0||pos>=size())
		return;
	Node* & pn=getptr(pos);
	Node* p=pn;
	pn=pn->next;
	delete p;
	--len;	
}
void List::remove(const T&d){
	int pos;
	while((pos=find(d))!=-1)
		erase(pos);
}
int List::find(const T& d)const{
	int pos=0;
	Node* p=head;
	while(p)
	{
		if(p->data==d)
			return pos;
		p=p->next;
		++pos;
	}
	return -1;
}
void List::set(int pos,const T& d){
	if(pos<0||pos>=size())
		return;
	getptr(pos)->data=d;
}
bool List::empty()const{
	return head==NULL;
}
T List::front()const{
	if(empty())
		throw "null";
	return head->data;
}
T List::back()const{
	if(empty())
		throw "null";
	Node* p=head;
	while(p->next!=NULL)
		p=p->next;
	return p->data;		
}
void List::inversion(){
	Node* p=head->next;
	Node* tmp;
	head->next=NULL;
	while(p!=NULL)
	{      
		tmp=p->next;
		p->next=head;
		head=p;
		p=tmp;
	}
}

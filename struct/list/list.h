#ifndef _LIST_H_
#define _LIST_H_
#include<iostream>
typedef int T;
class List{
private:
	struct Node{ 
		T data;
		Node* next;
		Node(const T& d=T()):data(d),next(0){}
	};
	Node* head;
	int len;
public:
	List():head(NULL),len(0){}
	void push_front(const T& d);
	List& push_back(const T& d);
	int size() const;
	Node* & getptr(int pos);
	void insert(const T&d,int pos);
	void travel() const;
	void clear();
	~List();
	void erase(int pos);
	void remove(const T&d);
	int find(const T& d)const;
	void set(int pos,const T& d);
	bool empty() const;
	T front() const;
	T back() const;
	void inversion();
};
#endif

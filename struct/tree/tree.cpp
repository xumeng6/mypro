#include<iostream>
#include<iomanip>
using namespace::std;
typedef char T;

class bst{
private:
	struct Node
	{
		T data;
		Node*  L;
		Node*  R;
		Node(const T& d):data(d),L(),R(){}
		Node(const T& d, Node* l,Node* r):data(d),L(l),R(r)
		{
		}	
	};
	typedef Node* tree;
	Node* rp;
	int n;
public:
	bst():rp(),n(){}
	void clear()
	{
		clear(rp);
		n=0;
	}
	~bst()
	{
		clear();
	}
	void insert(const T& d)
	{
		insert(rp,new Node(d));
		++n;
	}
	tree& find(const T& d)
	{
		return find(rp,d);
	}
	void travel()const
	{
		travel(rp);
		cout<<endl;
	}
	bool empty()const 
	{
		return rp==NULL;
	}
	bool remove(const T& d)
	{
		tree& t=find(d);
		if(t==NULL)
			return false;
		Node* p=t;
		if(t->L!=NULL)
			insert(t->R,t->L);
		t=t->R;
		delete p;
		--n;
		return true;	
	}
	const T& root() const
	{
		if(!rp)
			throw "the tree is NUll";
		return rp->data;
	}
	int size()const
	{
		return n;
	}
	void update(const T& olddata,const T& newdata)
	{
		if(remove(olddata))
			insert(newdata);
	}
	void insert(tree& t, Node* p)
	{
		if(t==NULL)
			t=p;
		else if(p->data <= t->data)
			insert(t->L,p);
		else insert(t->R,p);
	}
	tree&  find(tree& t, const T& d)
	{
		if(t==NULL)
			return t; 
		else if(d==t->data)
			return t;
		else if(d < t->data)
			return find(t->L,d);
		else 
			return find(t->R,d);
	}
	void travel(tree t )const
	{
		if(t!= NULL)
		{
			travel(t->L);
			cout<<t->data<<' ';
			travel(t->R);
		}
	}
	void clear(tree t)
	{
		if(t!=NULL)
		{
			clear(t->L);
			clear(t->R);
			delete t;
			t=NULL;
		}
	}
	int high(tree t)
	{
		if(t=NULL) 
			return 0;
		int lh = high(t->L);
		int rh = high(t->R);
		return 1+(lh>rh? lh:rh);//nice recursion algorithm
	}
	void print(tree t,int space,char sign)
	{
		if(t==NULL) return;
		print(t->R,space+3,'/');
		cout<< setw(space+1)<< sign<<t->data<<endl;
		print(t->L,space+3,'\\');
	}
	void print()
	{
		print(rp,0,'*');
		cout<<"-----------"<<endl;
	}

};
int main()
{
	bst b;
	b.insert('k');
	b.insert('a');
	b.insert('x');
	b.insert('h');
	b.insert('c');
	b.insert('u');
	b.insert('p');
	b.insert('r');
	b.insert('s');
	b.insert('m');
	b.insert('v');
	b.insert('l');
	b.travel();
	b.print();
	b.remove('x');
	b.remove('n');
	b.remove('s');
	b.travel();
	b.update('c','k');
	b.travel();
	while(!b.empty())
		b.remove(b.root());
	cout<<"size:"<<b.size()<<endl;
	b.travel();
}

#include<iostream>
using namespace std;

#include "stack.h"

int main()
{
	Stack<double> stack;
	
	stack.push(1.1);
	stack.push(2.2);
	stack.push(3.3);
	int len =stack.size();
	cout <<"stack len is: "<<len<<endl;
        StackIterator<double> it(stack);
	for(int i =0;i<len; i++)
	{
		cout << it++ <<endl;
	}
	cout<<"pop"<<endl;
	cout<< stack.pop()<<endl;
return 0;
	
}

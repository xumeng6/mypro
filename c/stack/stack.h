#ifndef _STACK_H_
#define _STACK_H_
namespace std{

template <typename T> class StackIterator;
template <typename T>
class Stack{
public:
	Stack()
	:top(0)
	{
	array[0]=T();	
	}
	int size() const
	{
		return top;
	}
	void push (const T& val);
	T pop();
	friend class StackIterator<T>;
private:
	enum{SIZE = 100};
	T array[SIZE];
	int top;
};
template <typename T>
void Stack<T>::push(const T& val)
{
	if(top<SIZE){
		array[top++] = val;
	}
}
template <typename T>
T Stack<T>::pop(){
    if(top>0)	{
	return array[--top];
    } 
	return array[0]	;
}
template <typename T>
class StackIterator{
public:
	StackIterator(Stack<T>& val)
	:stack(val),index(0)
	{}
 T& operator++(int)
{
	int ret = index;
	if(index < stack.top-1){
	index++;
        }
	return stack.array[ret];
}
private:
	Stack<T>& stack;
	int index;

};
}








#endif

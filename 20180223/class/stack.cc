 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-23 20:22:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
private:
	int a[10];
	int _size;
public:
	Stack(int size)
	:_size(size){}
	void push(int val);
	void pop();
	int top();
	bool empty();
	bool full();
	void print();
};
void Stack::print()
{
	int i;
	for(i=0;i<_size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void Stack::push(int val)
{
	a[_size]=val;
	_size++;
}
void Stack::pop()
{
	_size--;
}
int Stack::top()
{
	return a[_size-1];
}
bool Stack::empty()
{
	if(0==_size)
	{
		cout<<"Stack is empty!"<<endl;
		return 1;
	}
	else
	{
		cout<<"Stack is not empty!"<<endl;
		return 0;
	}
}
bool Stack::full()
{
	if(10==_size)
	{
		cout<<"Stack is full!"<<endl;
		return 1;
	}
	else
	{
		cout<<"Stack is not full!"<<endl;
		return 0;
	}
}
int main()
{
	int val;
	Stack s(0);
	s.empty();
	s.push(10);
	s.print();
	s.push(12);
	s.print();
	s.push(14);
	s.print();
	val=s.top();
	cout<<"top="<<val<<endl;
	s.pop();
	s.print();
	val=s.top();
	cout<<"top="<<val<<endl;
	s.full();
	return 0;
}

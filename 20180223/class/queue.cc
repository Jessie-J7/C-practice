 ///
 /// @file    queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-23 21:13:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue
{
	private:
		int a[10];
		int _front;
		int _back;
	public:
		Queue()
		:_front(0)
		,_back(0)
		{}
		void push(int);
		void pop();
		int front();
		int back();
		bool empty();
		bool full();
		void print();
};
void Queue::push(int val)
{
	a[_front]=val;
	_front++;
}
void Queue::pop()
{
	_back++;
}
int	Queue::front()
{
	return a[_front-1];
}
int	Queue::back()
{
	return a[_back];
}
bool Queue::empty()
{
	if(_front==_back)
	{
		cout<<"Queue is empty!"<<endl;
		return 1;
	}
	else
	{
		cout<<"Queue is not empty!"<<endl;
		return 0;
	}
}
bool Queue::full()
{
	if(_front+1==_back)
	{
		cout<<"Queue is full!"<<endl;
		return 1;
	}
	else
	{
		cout<<"Queue is not full!"<<endl;
		return 0;
	}
}

void Queue::print()
{
	int i;
	for(i=_back;i<_front;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	int val;
	Queue q;
	q.empty();
	q.push(10);
	q.print();
	q.push(12);
	q.print();
	q.push(14);
	q.print();
	val=q.front();
	cout<<"front="<<val<<endl;
	val=q.back();
	cout<<"back="<<val<<endl;
	q.pop();
	q.print();
	q.full();
	return 0;
}

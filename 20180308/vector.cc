 ///
 /// @file    vector.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-08 19:55:53
 ///


#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
	public:
		Vector();
		~Vector();

		void push_back(const T & value);
		void pop_back();

		int size()const;
		int capacity()const;

	private:
		void reallocate();

	private:
		static std::allocator<T> _alloc;

		T * _start;
		T * _finish;
		T * _end_of_storage;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
:_start(0)
,_finish(0)
,_end_of_storage(0)
{

}

template <typename T>
Vector<T>::~Vector()
{
	while(_start != _finish)
		_alloc.destroy(--_finish);
	_alloc.deallocate(_start,capacity());
}

template <typename T>
int Vector<T>::size() const
{
	return _finish - _start;
}

template <typename T>
int Vector<T>::capacity() const
{
	return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity())
	{
		reallocate();
	}
	_alloc.construct(_finish,value);
	++_finish;
}

template <typename T>
void Vector<T>::pop_back()
{
	_alloc.destroy(--_finish);
}

template <typename T>
void Vector<T>::reallocate()
{
	int oldcapacity=capacity();
	int newcapacity = (oldcapacity == 0 ? 1 : 2 * oldcapacity);

	T * newStart = _alloc.allocate(newcapacity);
	if(_start)
	{
		std::uninitialized_copy(_start,_finish,newStart);
		while(_start != _finish)
			_alloc.destroy(--_finish);
		_alloc.deallocate(_start,oldcapacity);
	}
	_start = newStart;
	_finish = _start + oldcapacity;
	_end_of_storage = _start + newcapacity;
}

void printSC(Vector<int> & vec)
{
	cout<<"size= "<<vec.size()<<endl;
	cout<<"capacity= "<<vec.capacity()<<endl;
}
int main()
{
	Vector<int> vec;
	vec.push_back(1);
	printSC(vec);
	vec.push_back(2);
	printSC(vec);
	vec.push_back(3);
	printSC(vec);
	vec.push_back(4);
	printSC(vec);
	vec.push_back(5);
	printSC(vec);
	vec.push_back(6);
	printSC(vec);
	vec.push_back(7);
	printSC(vec);
}

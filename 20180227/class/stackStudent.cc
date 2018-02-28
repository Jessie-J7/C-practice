 ///
 /// @file    stackStudent.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 20:11:14
 ///
#include <string.h> 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
	public:
		Student(const char *name,int id)
		:_name(new char[strlen(name)+1]())
		,_id(id)
		{
			cout<<"Student(const char *name,int id)"<<endl;
			strcpy(_name,name);
		}
		~Student()
		{
			cout<<"~Student()"<<endl;
			delete [] _name;
		}

		void print() const
		{
			cout<<"_name="<<_name<<endl;
			cout<<"_id="<<_id<<endl;
		}
	private:
		void * operator new(size_t size)
		{
			cout<<"operator new()"<<endl;
			void *ret=malloc(size);
			cout<<"size="<<size<<endl;
			return ret;
		}
		void operator delete(void *ret)
		{
			cout<<"operator delete()"<<endl;
			free(ret);
		}
		char *_name;
		int _id;
};

int main()
{
	//如果创建栈对象，要求构造函数和析构函数都在public
	Student s1("faith",100);
	
//	Student *pstu=new Student("rose",101);
//	pstu->print();

//	delete pstu;
	return 0;
}

///
/// @file    homework.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-02-23 17:08:10
///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String()
		{
			cout<<"String()"<<endl;
		}
		String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1]())
		{
			cout<<"String(const char *pstr)"<<endl;
			strcpy(_pstr,pstr);
		}
		String(const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			cout<<"String(const String & rhs)"<<endl;
			strcpy(_pstr,rhs._pstr);
		}

		String & operator=(const String & rhs)
		{
			cout<<"String & operator=(const String & rhs)"<<endl;
			_pstr=new char[strlen(rhs._pstr)+1]();
			strcpy(_pstr,rhs._pstr);
			return *this;
		}
		~String()
		{
			cout<<"~String()"<<endl;
			_pstr=NULL;
		}

		void print();

	private:
		char * _pstr;
};
void String::print()
{
	cout<<"String="<<_pstr<<endl;
}

int main(void)
{
	String str1;//默认构造函数
	str1.print();

	String str2 = "Hello,world";//
	String str3("wangdao");//有参构造函数

	str2.print();		
	str3.print();	

	String str4 = str3;//复制构造函数
	str4.print();

	str4 = str2;//赋值
	str4.print();

	return 0;
}

 ///
 /// @file    point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-23 14:46:20
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	private:
		char *_brand;
		float _price; 
	public:
		Computer(const char *brand,float price)
		//:_brand(brand)//浅拷贝
		:_brand(new char[strlen(brand)+1]())//深拷贝
		,_price(price)
		{
			cout<<"Computer(const char *,float)"<<endl;
			strcpy(_brand,brand);
		}
		Computer(const Computer & rhs)
		:_brand(new char[strlen(rhs._brand)+1]())//深拷贝
		,_price(rhs._price)
		{
			cout<<"Computer(const Computer & rhs)"<<endl;
			strcpy(_brand,rhs._brand);
		}
		void print();

		~Computer()
		{
			cout<<"~Computer"<<endl;
			delete [] _brand;
		}
};
void Computer::print()
{
	cout<<"品牌"<<_brand<<endl;
	cout<<"价格"<<_price<<endl;
}

int main()
{

	Computer com1("mac",10000);//栈对象
	com1.print();

	Computer com2=com1;
	com2.print();
	return 0;
}

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
		void print();

		void setBrand(const char *brand);
		void setPrice(float price);
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

Computer com2("thinkpad",6666);//全局对象
int main()
{
//	Computer com;
//	com.setBrand("xiaomi");
//	com.setPrice(4999);
//	com.print();

	Computer com1("mac",10000);//栈对象
	com1.print();

	Computer * p=new Computer("xiaomi",4999);//堆对象
	p->print();
	delete p;

	return 0;
}

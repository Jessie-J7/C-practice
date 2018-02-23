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
		char _brand[20];
		float _price; 
	public:
		void print()
		{
			cout<<"品牌"<<_brand<<endl;
			cout<<"价格"<<_price<<endl;
		}

		void setBrand(const char *brand)
		{
			strcpy(_brand,brand);
		}
		void setPrice(float price)
		{
			_price=price;
		}
};

int main()
{
	Computer com;
	com.setBrand("xiaomi");
	com.setPrice(4999);
	com.print();

	return 0;
}

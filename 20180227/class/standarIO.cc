 ///
 /// @file    standarIO.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 20:55:59
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void printCin()
{
	cout<<"cin's badbit="<<cin.bad()<<endl;
	cout<<"cin's failbit="<<cin.fail()<<endl;
	cout<<"cin's eofbit="<<cin.eof()<<endl;
	cout<<"cin's goodbit="<<cin.good()<<endl;
}

int main()
{
	printCin();

	int number;

	while(cin>>number)
	{
		cout<<"number="<<number<<endl;
	}

	printCin();

	cout<<"重置"<<endl;
	cin.clear();
	printCin();

	cout<<"清空"<<endl;
//	cin.ignore(1024,'\n'); 
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	string line;
	cin>>line;

	cout<<"line="<<line<<endl;
	return 0;
}

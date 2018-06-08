 ///
 /// @file    standarIO2.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 21:14:38
 ///
 
#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;
int main()
{
	int number;

	cout<<"please input :"<<endl;
	while(cin>>number,!cin.eof())
	{
		if(cin.bad())
		{
			cout<<"io has corrupted!"<<endl;
			return -1;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout<<"please input :"<<endl;
			continue;
		}
		cout<<"number="<<number<<endl;
	}
	return 0;
}



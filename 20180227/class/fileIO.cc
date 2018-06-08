 ///
 /// @file    fileIO.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 21:37:29
 ///
 
#include <string.h>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;

using std::ifstream;

void test1()
{
	ifstream ifs("test.txt");
	if(!ifs)
	{
		cout<<"ifstream open error!"<<endl;
		return ;
	}

//	string word;
//	while(ifs>>word)//以空格作为分隔符
//	{
//		cout<<"word="<<word<<endl;
//	}

	string line;
	while(getline(ifs,line))
	{
		cout<<line<<endl;
	}
}

int main()
{
	test1();
	return 0;
}

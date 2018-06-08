 ///
 /// @file    fileIO2.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 21:37:29
 ///
 
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using std::ifstream;

void test1()
{
//	ifstream ifs("test.txt");
	ifstream ifs;
	ifs.open("test.txt");
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

	vector<string> lines;
	lines.reserve(50);
	string line;
	while(getline(ifs,line))
	{
		lines.push_back(line);
//		cout<<line<<endl;
	}

	for(auto & elem : lines)
	{
		cout<<elem<<endl;
	}
}

int main()
{
	test1();
	return 0;
}

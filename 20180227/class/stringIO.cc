 ///
 /// @file    stringIO.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 14:58:53
 ///
 
#include <iostream>
#include <sstream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;

using std::stringstream;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
void test1()
{
	int val1=10;
	int val2=20;

	stringstream ss;
	ss<<"val1= "<<val1<<" val2= "<<val2<<endl;

	string line = ss.str();
	cout<<line<<endl;

	string word;
	string number;

	while(!ss.eof())
	{
		ss>>word;
		ss>>number;

		cout<<"word= "<<word<<endl;
		cout<<"number= "<<number<<endl;
	}
}

string int2str(int number)
{
	ostringstream oss;
	oss<<number;
	return oss.str();
}

void readconfig()
{
	istringstream iss;
	string key;
	string value;

	ifstream ifs("my.conf");
	if(!ifs.good())
	{
	}
	string line;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		iss>>key>>value;
		cout<<key<<":"<<value<<endl;
	}
}
int main()
{
//	test1();
	readconfig();
	return 0;
}

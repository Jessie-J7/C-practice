 ///
 /// @file    fileIO4.cc
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
using std::cin;

using std::ifstream;
using std::ofstream;
using std::fstream;
vector<string> lines;

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
	ifs.close();
}

void test2()
{
	string filename="test1.txt";
	ofstream ofs(filename);
	if(!ofs.good())
	{
		return;
	}
	for(auto & elem : lines)
	{
		ofs<<elem<<'\n';
	}
	ofs.close();
}

void test3()
{
	fstream fs("test.txt");
	if(!fs.good())
	{
		cout<<"fstream open error"<<endl;
		return ;
	}
	int number;
	
	cout<<"filepointer="<<fs.tellg()<<endl;
	for(int i=1;i<11;i++)
	{
//		cin>>i;
		fs<<i<<" ";
		cout<<"filepointer="<<fs.tellg()<<endl;
	}

	fs.seekg(std::ios::beg);
	for(int i=1;i<11;i++)
	{
		fs>>number;
		cout<<number<<" ";
	}
	cout<<endl;
}

int main()
{
//	test1();
//	test2();
	test3();
	return 0;
}

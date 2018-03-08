 ///
 /// @file    map.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-06 10:33:47
 ///
 
#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

void test1()
{
	pair<int,string>sz[4]={
		pair<int,string>(1,"a"),
		pair<int,string>(2,"a"),
		pair<int,string>(3,"a"),
		pair<int,string>(2,"a")
	};
	map<int,string>mapInt(sz,sz+4);

	mapInt[2]="b";
	mapInt[4]="c";
	for(auto elem : mapInt)
	{
		cout<<elem.first<<"-->"<<elem.second<<endl;
	}
}

int main()
{
	test1();
	return 0;
}

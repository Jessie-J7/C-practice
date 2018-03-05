 ///
 /// @file    set.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-05 19:44:49
 ///
 
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::multiset;
using std::set;


void test1()
{
	cout<<"set"<<endl;
	set<int,std::greater<int>>key={1,3,4,7,3,1,6,5,9,7,8};
	for(auto & elem : key)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}
void test2()
{
	cout<<"multiset"<<endl;
	multiset<int,std::greater<int>>key={1,3,4,7,3,1,6,5,9,7,8};
	for(auto & elem : key)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}

int main()
{
	test1();
	test2();
	return 0;
}


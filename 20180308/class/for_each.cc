 ///
 /// @file    for_each.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-08 10:43:54
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
typedef vector<int> vi;
typedef vi::iterator vip;

void func(vi::value_type v)
{
	cout<<v<<" ";
}

int main()
{
	int sz[]={1,2,3,4,5};
	vi ob(sz,sz+5);
	std::for_each(ob.begin(),ob.end(),func);
	cout<<endl;
	return 0;
}


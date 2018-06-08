 ///
 /// @file    sequential.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-05 15:38:54
 ///
#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

void test1()
{
	cout<<"vector"<<endl;
	int sz[]={1,2,3,4,5,6,7,8,9};
	vector<int>vecInt(sz,sz+9);

	vector<int>::iterator it;
	it=vecInt.begin();
	cout<<*it<<endl;
	++it;
	vecInt.insert(it,999);
	cout<<*it<<endl;
	vecInt.insert(it,2,88);
	cout<<*it<<endl;
	vecInt.insert(it,sz,sz+3);
	cout<<*it<<endl;
	for (size_t i=0;i!=vecInt.size();++i)
	{
		cout<<vecInt[i]<<" ";
	}
	cout<<endl;
}

void test2()
{
	cout<<"deque"<<endl;
	int sz[10]={1,2,3,4,5,6,7,8,9,0};
	deque<int>deqInt(sz,sz+10);

//	deqInt.push_front(666);
//	cout<<"front:"<<deqInt[0]<<endl;
	
	deque<int>::iterator it;
	it=deqInt.begin();
	++it;
	deqInt.insert(it,999);
	cout<<*it<<endl;
	deqInt.insert(it,2,88);
	cout<<*it<<endl;
	deqInt.insert(it,sz,sz+3);
	cout<<*it<<endl;
	deqInt.insert(it,it+4,it+5);
	cout<<*it<<endl;
	for (int i=0;i<deqInt.size();i++)
	{
		cout<<deqInt[i]<<" ";
	}
	cout<<endl;
}

void test3()
{
	cout<<"list"<<endl;
	int sz[10]={1,2,3,4,5,6,7,8,9,0};
	list<int>liInt(sz,sz+10);

//	liInt.push_front(666);
	list<int>::iterator it=liInt.begin();
	cout<<*it<<endl;
	++it;
	liInt.insert(it,999);
	liInt.insert(it,2,88);
//	liInt.insert(it,liInt.begin(),liInt.end());
	liInt.insert(it,sz,sz+3);
	for(it=liInt.begin();it!=liInt.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main()
{
//	test1();
	test2();
	test3();
	return 0;
}

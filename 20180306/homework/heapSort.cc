 ///
 /// @file    heapSort.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-06 20:23:56
 ///
#include "Point.h"
#include "heapSort.h"
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::string;

void test1()
{
	int arr[]={2,4,6,1,8,7,3,9};
	HeapSort<int,std::less<int> > hs(arr,8);
	hs.sort();
	cout<<"T : int"<<endl;
	hs.print();
}

void test2()
{
	float arr1[]={2.1,3.2,1.5,6.3,4.7};
	HeapSort<float,std::less<float> >hs1(arr1,5);
	hs1.sort();
	cout<<"T : float"<<endl;
	hs1.print();
}

void test3()
{
	Point arr2[]={
		Point(1,2),
		Point(2,3),
		Point(0,0),
		Point(2,0)
		};
	HeapSort<Point,Compare> hs2(arr2,4);
	hs2.sort();
	cout<<"T : Point"<<endl;
	hs2.print();
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}

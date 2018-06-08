 ///
 /// @file    point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-23 15:29:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	private:
		int _ix;
		int _iy;
	public:
		Point()
		{}
		Point(int ix,int iy)
		{
			cout<<"Point(int,int)"<<endl;
			_ix=ix;
			_iy=iy;
		}
		void print()
		{
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
};

int main()
{
	Point p(1,2);
	p.print();
}

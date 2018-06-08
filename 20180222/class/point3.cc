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
#if 0
		Point()
		{}
#endif
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout<<"Point(int,int)"<<endl;
		}
		Point(const Point & rhs)
		:_ix(rhs._ix)
		,_iy(rhs._iy)
		{
			cout<<"Point(const Point & rhs)"<<endl;
		}
		void print()
		{
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		~Point()
		{
			cout<<"~Point()"<<endl;
		}
};

int main()
{
	Point p(1,2);
	p.print();

	Point p1=p;
	p1.print();
	return 0;
}

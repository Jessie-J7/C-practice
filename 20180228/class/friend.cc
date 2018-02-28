 ///
 /// @file    friend.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 10:37:36
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	friend float distance(const Point & lhs,const Point &rhs);
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout<<"Point(int,int)"<<endl;
		}
		void print();
	private:
		int _ix;
		int _iy;
};

void Point::print()
{
	cout<<_ix<<","<<_iy<<endl;
}

float distance(const Point & lhs,const Point &rhs)
{
	float length=sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+
				(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
	return length;
}

int main()
{
	Point p1(1,2);
	Point p2(3,4);

	p1.print();
	p2.print();
	cout<<"dis="<<distance(p1,p2)<<endl;
}

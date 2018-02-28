 ///
 /// @file    friend2.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 10:37:36
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;

class Point;

class Line
{
	public:
		Line(int len=0)
		:_len(len)
		{
			cout<<"Line()"<<endl;
		}
		float distance(const Point & lhs,const Point &rhs);

		void setPoint(Point & rhs,int ix,int iy);
	private:
		int _len;
};


class Point
{
	friend class Line;
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout<<"Point(int,int)"<<endl;
		}
		void print();
		void setL(Line & rhs,int il)
		{
			rhs._len=il;
		}
	private:
		int _ix;
		int _iy;
};

void Point::print()
{
	cout<<_ix<<","<<_iy<<endl;
}

float Line::distance(const Point & lhs,const Point &rhs)
{
	float length=sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+
				(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
	return length;
}

void Line::setPoint(Point &rhs,int ix,int iy)
{
	rhs._ix=ix;
	rhs._iy=iy;
}

int main()
{
	Point p1(1,2);
	Point p2(3,4);

	p1.print();
	p2.print();
	Line line;
	cout<<"dis="<<line.distance(p1,p2)<<endl;

	line.setPoint(p1,5,6);
	p1.print();
}

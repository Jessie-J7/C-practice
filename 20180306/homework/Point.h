 ///
 /// @file    Point.h
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-06 22:16:48
 ///
 
#ifndef __WD_POINT_H__
#define __WD_POINT_H__

#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;



class Point
{
	public:
		Point(int ix=0,int iy=0)
		:_ix(ix)
		,_iy(iy)
		{}

		int distance() const
		{
			return sqrt(_ix * _ix + _iy * _iy);
		}
		friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
	private:
		int _ix;
		int _iy;
};

bool operator<(const Point & lhs,const Point & rhs)
{
	return lhs.distance() < rhs.distance();
}

struct Compare
{
	bool operator()(const Point & lhs,const Point & rhs)
	{
		return lhs.distance() < rhs.distance();
	}
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
	os<<"("<<rhs._ix
	  <<","<<rhs._iy
	  <<")";
	return os;
}

#endif

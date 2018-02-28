 ///
 /// @file    complex3.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 19:55:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
	public:
		Complex(double dreal,double dimag)
		:_dreal(dreal)
		,_dimag(dimag)
		{
			cout<<"Complex(double,double)"<<endl;
		}
		void display()const
		{
			cout<<_dreal;
			if(_dimag>0)
			{
				cout<<" + "<<_dimag<<"i"<<endl;
			}else if(_dimag<0)
				cout<<" - "<<_dimag*(-1)<<"i"<<endl;
			else 
				cout<<endl;
		}
		Complex & operator+=(const Complex & rhs)
		{
			_dreal += rhs._dreal;
			_dimag += rhs._dimag;

			return *this;
		}
		//前置++
		Complex & operator++()
		{
			++_dreal;
			++_dimag;

			return *this;
		}
		//后置++
		Complex operator++(int)
		{
			Complex temp(*this);
			++_dreal;
			++_dimag;
			
			return temp;
		}
		friend Complex operator+(const Complex & lhs,const Complex & rhs);

	private:
		double _dreal;
		double _dimag;
};

Complex operator+(const Complex & lhs,const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
					lhs._dimag + rhs._dimag);
}

int main()
{
	Complex c1(1,2);
	Complex c2(2,-1);

	cout<<"c1 = ";
	c1.display();

	cout<<"c2 = ";
	c2.display();
	
	Complex c3=c1+c2;
	cout<<"c3 = ";
	c3.display();

	c1 += c2;
	cout<<"c1 = ";
	c1.display();
	
	++c1;
	cout<<"前置c1 = ";
	c1.display();
	
	c1++;
	cout<<"后置c1 = ";
	c1.display();
	return 0;
}

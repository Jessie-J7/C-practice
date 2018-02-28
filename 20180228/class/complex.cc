 ///
 /// @file    complex.cc
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
		}
	private:
		double _dreal;
		double _dimag;
};

#if 0
int operator+(int x,int y)
{
	return x-y;
}
#endif

int main()
{
	Complex c1(1,2);
	Complex c2(2,-1);
	Complex c3(0,0);
	Complex c4(0,-1);
	Complex c5(1,0);

	cout<<"c1 = ";
	c1.display();

	cout<<"c2 = ";
	c2.display();

	cout<<"c3 = ";
	c3.display();
	cout<<endl;

	cout<<"c4 = ";
	c4.display();
//	cout<<endl;

	cout<<"c5 = ";
	c5.display();
	cout<<endl;

	int a=1,b=2;
	int c=a+b;

	Complex c6=c1+c2;

	return 0;
}

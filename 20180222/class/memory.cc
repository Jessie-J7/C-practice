 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-22 10:45:58
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a=0;
char *p1;
const int d=100;
int main()
{
	int b;
	char s[]="123456";
	char *p2;
	const char *p3="123456";
	static int e=10;
	static int c=0;
	p1=new char[10];
	p2=new char[5];

	printf("&a=%p\n",&a);
	printf("&b=%p\n",&b);
	printf("&p1=%p\n",&p1);
	printf("p1=%p\n",p1);
	printf("&d=%p\n",&d);
	printf("s=%p\n",s);
	printf("&p2=%p\n",&p2);
	printf("p2=%p\n",p2);
	printf("&p3=%p\n",&p3);
	printf("p3=%p\n",p3);
	printf("&e=%p\n",&e);
	printf("&c=%p\n",&c);

	return 0;
}

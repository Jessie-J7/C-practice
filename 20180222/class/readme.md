memory.cc   内存与地址空间

computer.cc 注意自己的代码书写风格 
类的公有成员和私有成员

computer2.cc  
类的公有成员的另一种定义方式，放在类的外面，在函数前需要 类名::

computer3.cc  
将class换成struct，不影响程序执行
但是class默认访问权限是private，struct默认访问权限是public。

point.cc
构造函数；
默认构造函数（无参）；
有参构造函数；
一旦用户定义了构造函数，系统将不再提供默认构造函数；

point2.cc
有参构造函数,初始化表达式： P(int ix,int iy):_ix(ix),_iy(iy)
析构函数使用；

computer4.cc
构造函数初始化char*，可以采用两种方式，浅拷贝和深拷贝；
深拷贝，在赋值前会申请地址空间，所以在程序执行完时，要delete/free；
析构函数，对于局部对象，程序执行完成，会调用析构函数；
堆对象，在程序执行过后，一定要delete申请的堆空间；
全局对象

point3.cc
复制构造函数；
类名(const 类名 & rhs)

computer5.cc
复制构造函数



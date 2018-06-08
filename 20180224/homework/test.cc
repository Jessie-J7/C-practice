 ///
 /// @file    test.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-01 19:54:26
 ///
#include "mutexLock.h" 
#include "condition.h"
#include <iostream>
using std::cout;
using std::endl;

MutexLock mutex;
Condition condition;
bool flag=false;
int number=0;

void *threadfunc1(void *arg)
{
	int cnt=10;
	while(cnt--)
	{
		MutexLockGuard mlg(mutex);
		//mutex.lock();
		if(!flag)
		{
			condition.wait(mutex);
		}
		++number;
		cout<<"threadfun1 number="<<number<<endl;
		if(flag)
			flag=false;
		condition.notify();
		//mutex.unlock();
	}
	return NULL;
}
void *threadfunc2(void *arg)
{
	int cnt=10;
	while(cnt--)
	{
		MutexLockGuard mlg(mutex);
		//mutex.lock();
		if(flag)
		{
			condition.wait(mutex);
		}
		++number;
		cout<<"threadfun2 number="<<number<<endl;
		if(!flag)
			flag=true;
		condition.notify();
		//mutex.unlock();
	}
	return NULL;
}


int main()
{
	pthread_t pth1;
	pthread_t pth2;

	pthread_create(&pth1,NULL,threadfunc1,NULL);
	pthread_create(&pth2,NULL,threadfunc2,NULL);

	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);
	return 0;
}

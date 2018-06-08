 ///
 /// @file    condition.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-01 20:13:39
 ///

#include "condition.h"
#include "mutexLock.h"
#include <iostream>
using std::cout;
using std::endl;

Condition::Condition()
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait(MutexLock & mutex)
{
	pthread_cond_wait(&_cond,mutex.getMutexLockPtr());
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

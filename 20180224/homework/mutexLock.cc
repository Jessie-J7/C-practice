 ///
 /// @file    mutexLock.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-01 19:49:24
 ///
 
#include "mutexLock.h"
#include <iostream>
using std::cout;
using std::endl;

MutexLock::MutexLock()
:isLocking(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	isLocking=true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	isLocking=false;
}


pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return &_mutex;
}


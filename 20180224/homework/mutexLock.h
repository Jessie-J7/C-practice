 ///
 /// @file    mutexLock.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-01 19:44:57
 ///
 
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__
#include <pthread.h>

class MutexLock
{

	public:
		MutexLock();
		~MutexLock();
		
		void lock();
		void unlock();

		pthread_mutex_t * getMutexLockPtr();

	private:
		MutexLock(const MutexLock & );
		MutexLock & operator=(const MutexLock &);

		pthread_mutex_t _mutex;
		bool isLocking;
};

class MutexLockGuard
{
	public:
		MutexLockGuard(MutexLock & mutex)
		:_mutex(mutex)
		{
			_mutex.lock();
		}
		~MutexLockGuard()
		{
			_mutex.unlock();
		}
	private:
		MutexLock & _mutex;
};

#endif

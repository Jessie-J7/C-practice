 ///
 /// @file    condition.h
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-01 20:03:07
 ///

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

class MutexLock;
class MutexLockGuard;

class Condition
{
	public:
		Condition();
		~Condition();

		void wait(MutexLock & mutex);

		void notify();
		void notifyall();

	private:
		pthread_cond_t _cond;
		
};

#endif

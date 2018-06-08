 ///
 /// @file    mylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-26 14:54:32
 ///
 //
#ifndef __WD_MYLOG_H__
#define __WD_MYLOG_H__

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Log
{
	public:
		static Log * getInstance();

		static void destroy();

		void info(const char * msg);
		void error(const char * msg);
		void warn(const char * msg);
		void debug(const char * msg);
	private:
		Log();
		~Log();
		log4cpp::Category & _cat;
		static Log * _pInstance;		
};

void logInfo(const char *);
void logError(const char *);
void logWarn(const char *);

inline string int2str(int num)
{
	std::ostringstream oss;
	oss << num;
	return oss.str();
}

#define prefix(msg) string("[").append(__FILE__).\
					append(":").append(__func__).\
					append(":").append(int2str(__LINE__)).\
					append("]").append(msg).c_str()

#define LogInfo(msg) logInfo(prefix(msg));
#define LogError(msg) logError(prefix(msg));
#define LogWarn(msg) logWarn(prefix(msg));
#endif

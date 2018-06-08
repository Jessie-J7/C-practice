 ///
 /// @file    mylog.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-26 16:10:48
 ///
 
#include "mylog.h"

Log * Log::_pInstance = NULL;

Log * Log::getInstance()
{
	if(NULL==_pInstance)
		_pInstance = new Log();
	return _pInstance;
}

Log::Log()
:_cat(log4cpp::Category::getRoot())
{
	log4cpp::Appender * ostreamAppender = new log4cpp::OstreamAppender("cout",&cout);

	log4cpp::Appender * fileAppender = new log4cpp::FileAppender("fileAppender","wangdao.log");

	log4cpp::PatternLayout * ptnLyt = new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt);
	
	log4cpp::PatternLayout * ptnLyt2 = new log4cpp::PatternLayout();
	ptnLyt2->setConversionPattern("%d [%p] %c: %m%n");
	fileAppender->setLayout(ptnLyt2);
	
	log4cpp::Category & _cat = log4cpp::Category::getRoot();
	_cat.addAppender(ostreamAppender);
	_cat.addAppender(fileAppender);
	_cat.setPriority(log4cpp::Priority::DEBUG);

}

Log::~Log()
{
	log4cpp::Category::shutdown();
}

void Log::destroy()
{
	if(_pInstance)
		delete _pInstance;
}

void Log::info(const char * msg)
{
	_cat.info(msg);
}
void Log::error(const char * msg)
{
	_cat.error(msg);
}
void Log::warn(const char * msg)
{
	_cat.warn(msg);
}

void logInfo(const char * msg)
{
	Log::getInstance()->info(msg);
}

void logError(const char * msg)
{
	Log::getInstance()->error(msg);
}

void logWarn(const char * msg)
{
	Log::getInstance()->warn(msg);
}

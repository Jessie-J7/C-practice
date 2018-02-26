 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-02-26 14:35:28
 ///

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	log4cpp::Appender * ostreamAppender = new log4cpp::OstreamAppender("cout",&cout);

	log4cpp::Appender * fileAppender = new log4cpp::FileAppender("fileAppender","wangdao.log");

	log4cpp::PatternLayout * ptnLyt = new log4cpp::PatternLayout();
	ptnLyt->setConversionPattern("%d [%p] %c: %m%n");
	ostreamAppender->setLayout(ptnLyt);

	log4cpp::PatternLayout * ptnLyt2 = new log4cpp::PatternLayout();
	ptnLyt2->setConversionPattern("%d [%p] %c: %m%n");
	fileAppender->setLayout(ptnLyt2);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(ostreamAppender);
	root.addAppender(fileAppender);

	root.setPriority(log4cpp::Priority::DEBUG);

	root.warn("warn");
	root.error("error");
	root.info("info");

	log4cpp::Category::shutdown();

	return 0;
}

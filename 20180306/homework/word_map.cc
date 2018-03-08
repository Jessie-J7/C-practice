 ///
 /// @file    work1.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 15:18:24
 ///
#include <time.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

using std::ifstream;
using std::ofstream;
using std::map;
using std::pair;

class WordStatistic
{
	public:
		void readFile(const string & filename);
		void writeFile(const string & filename);
	private:
		map<string,int>dic;
};

void WordStatistic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout<<"ifs open error"<<endl;
	}
	string word;
	while(ifs>>word)
	{
		pair<map<string, int>::iterator, bool> ret = dic.insert(pair<string,int>(word,1));
		if(!ret.second)
		{
			ret.first->second++;
		}
	}
	ifs.close();
}

void WordStatistic::writeFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout<<"ofs open error"<<endl;
	}
	for(auto elem : dic)
	{
		ofs<<elem.first<<" "<<elem.second<<endl;
	}
	ofs.close();
}
int main()
{
	clock_t start,end;
	start = clock();
	string fileinname="The_Holy_Bible.txt";
	WordStatistic ws;
	ws.readFile(fileinname);
	string fileoutname="file.txt";
	ws.writeFile(fileoutname);
	end = clock();
	cout<<"total time :"<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}

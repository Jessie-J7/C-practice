 ///
 /// @file    work1.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-28 15:18:24
 ///
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

using std::ifstream;
using std::ofstream;
using std::vector;

struct dictionary
{
	string word;
	int value;
};

class WordStatistic
{
	public:
		void readFile(const string & filename);
		void writeFile(const string & filename);
	private:
		vector<dictionary>dic;
};

void WordStatistic::readFile(const string & filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout<<"ifs open error"<<endl;
	}
	dictionary dict;
	string word;
	int flag;
	while(ifs>>word)
	{
		flag=0;
		for(int i=0;i<dic.size();i++)
		{
			if(dic.at(i).word==word)
			{
				dic.at(i).value++;
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		dict.word=word;
		dict.value=1;
		dic.push_back(dict);
	}
	ifs.close();
}

bool comp(const dictionary & d1,const dictionary & d2)
{
	return d1.value > d2.value;
}

void WordStatistic::writeFile(const string & filename)
{
	ofstream ofs(filename.c_str());
	if(!ofs.good())
	{
		cout<<"ofs open error"<<endl;
	}
	sort(dic.begin(),dic.end(),comp);
	for(int i=0;i<dic.size();i++)
	{
		ofs<<dic.at(i).word<<" "<<dic.at(i).value<<endl;
	}
	ofs.close();
}
int main()
{
	string inname="The_Holy_Bible.txt";
	WordStatistic ws;
	ws.readFile(inname);
	string outname="file";
	ws.writeFile(outname);
	return 0;
}

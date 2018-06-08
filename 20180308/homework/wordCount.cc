 ///
 /// @file    wordCount.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-08 21:29:32
 ///
 
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

class TextQuery
{
	public:
		void readFile(const string filename);
		void query(const string & word);

	private:
		vector<string> lines;
		map<string,set<int> > word2Line;
		map<string,int> dict;
};

void TextQuery::readFile(const string filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout<<"ifs open error"<<endl;
	}
	set<int> myset;
	string line;
	int lino=0;
	while(getline(ifs,line))
	{
		++lino;
		lines.push_back(line);
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			pair<map<string, int>::iterator, bool> ret = dict.insert(pair<string,int>(word,1));
			if(!ret.second)
			{
				ret.first->second++;
				auto it = word2Line.find(word);
				it->second.insert(lino);
			}else{
				myset.insert(lino);
				word2Line.insert(make_pair(word,myset));
				myset.clear();
			}
		}
	}
	ifs.close();
}

void TextQuery::query(const string & word)
{
	auto dict_it = dict.find(word);
	if(word == dict_it->first)
	{
		cout<<word<<" occurs "<<dict_it->second<<" times."<<endl;
		auto word_it = word2Line.find(word);
		for(auto elem : word_it->second)
		{
			cout<<"(line: "<<elem<<")"<<lines[elem-1]<<endl;
		}
	}
}

int main()
{
	string queryWord("the");

	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query(queryWord);
	return 0;
}

 ///
 /// @file    vector.cc
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-02-27 21:50:18
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void print(vector<int> & vec)
{
	cout<<"vec's size="<<vec.size()<<endl;
	cout<<"vec's capacity="<<vec.capacity()<<endl;
}


int main()
{
	vector<int>numbers;
	numbers.reserve(5);
	
	print(numbers);
	numbers.push_back(1);
	print(numbers);
	numbers.push_back(2);
	print(numbers);
	numbers.push_back(3);
	print(numbers);
	numbers.push_back(4);
	print(numbers);
	numbers.push_back(5);
	print(numbers);
	numbers.push_back(6);
	print(numbers);

	for(size_t idx=0;idx<numbers.size();++idx)
	{
		cout<<numbers[idx]<<" ";
	}
	cout<<endl;
}

 ///
 /// @file    heapSort.h
 /// @author  khfaith(kh_faith@qq.com)
 /// @date    2018-03-06 22:18:31
 ///
#ifndef __WD_HEAPSORT_H__ 
#define __WD_HEAPSORT_H__ 

#include <iostream>
using std::cout;
using std::endl;


template <class T,typename Compare = std::less<T> >

class HeapSort
{
	public:
		HeapSort(T * arr,int size)
		:_size(size)
		,_arr(new T[size]())
		{
			for(int i=0;i!=size;i++)
				_arr[i]=arr[i];
		}
		void heapAdjust(T * arr,int i,int length)
		{
			T temp = arr[i];
			for(int k=i*2+1;k<length;k=k*2+1)
			{
				if(k+1<length && arr[k]<arr[k+1])
					k++;
				if(temp < arr[k])
				{
					arr[i] = arr[k];
					i = k;
				}else
					break;
			}
			arr[i] = temp;
		}
		void sort()
		{
			for(int i=_size/2-1;i>=0;i--)
			{
				heapAdjust(_arr,i,_size);
			}
			for(int j=_size-1;j>0;j--)
			{
				swap(_arr,0,j);
				heapAdjust(_arr,0,j);
			}
		}
		void swap(T * arr,int a,int b)
		{
			T temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}
		void print()
		{
			for(int i=0;i!=_size;i++)
				cout<<_arr[i]<<" ";
			cout<<endl;
		}
	private:
		int _size;
		T * _arr;
};

#endif

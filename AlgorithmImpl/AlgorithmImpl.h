// AlgorithmImpl.h

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

namespace AlgorithmImpl {

	class Utility
	{
	public:
		static vector<int> Utility::createVector(int arr[], int len)
		{
			vector<int> vec;
			for(int i = 0;i<len;++i)
			{
				vec.push_back(arr[i]);
			}
			return vec;
		}

		static 	void Utility::printVector(const vector<int> &vec)
		{
			for(vector<int>::size_type i = 0; i < vec.size(); ++i)
			{
				cout << vec[i] << " ";
			}
			cout << endl;
		}
	};

	class MSAlgorithm
	{
	public:
		static void arrayToLinkedList(vector<int> & array, list<vector<int>> &list)
		{
			sort(array.begin(), array.end());
			vector<int> vec;
			for(vector<int>::size_type i=0; i<array.size(); ++i)
			{
				if(0==i)
				{
					vec.push_back(array[i]);
				}
				else
				{
					if(array[i] != (array[i-1] + 1))
					{
						list.push_back(vec);
						vec.clear();
						vec.push_back(array[i]);
					}
					else
					{
						vec.push_back(array[i]);
					}
				}
				if(array.size() - 1 == i && 0 != vec.size())
				{
					list.push_back(vec);
				}
			}
		}

		static void testArrayToLinkedList()
		{
			int arr[16] = {1, 3,4,5,8,9,11,13,14,15,16,20, 23,30,31,32};
			vector<int> vec = Utility::createVector(arr,16);
			list<vector<int> >li;
			MSAlgorithm::arrayToLinkedList(vec, li);

			for(list<vector<int> >::const_iterator i = li.begin(); i != li.end(); ++i)
			{
				Utility::printVector( *i );
			}
		}
	};
}

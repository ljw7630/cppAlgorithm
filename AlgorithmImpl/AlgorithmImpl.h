// AlgorithmImpl.h

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

typedef void (*FunctionPtr)();

namespace AlgorithmImpl {

	class Utility
	{
	public:
		static int my_partition(vector<int> &a, int s, int e){
			int x = a[e];
			int idx = s;
			for(int i = s; i<e;++i){
				if(a[i] <= x){
					swap(a[idx], a[i]);
					idx++;
				}
			}
			swap(a[idx],a[e]);
			return idx;
		}

		static void my_quick_sort(vector<int> &a, int s, int e){
			if( s<e ){
				int pivot = my_partition(a, s, e);
				my_quick_sort(a, s, pivot-1);
				my_quick_sort(a, pivot+1, e);
			}
		}

		static pair<clock_t, clock_t> Utility::measureTime(FunctionPtr ptr)
		{
			clock_t init = clock();
			ptr();
			clock_t final = clock();
			return make_pair(init, final);
		}
	
		static void Utility::printMeasureTime(FunctionPtr ptr)
		{
			pair<clock_t, clock_t> timePair = measureTime(ptr);
			
			cout << "Duration: " << (double) (timePair.second - timePair.first) / (double) CLOCKS_PER_SEC << endl;
		}

		template <typename T>
		static vector<T> createVector(T arr[], int len)
		{
			vector<T> vec;
			for(int i = 0;i<len;++i)
			{
				vec.push_back(arr[i]);
			}
			return vec;
		}
		
		template <typename T>
		static void printVector(const vector<T> &vec)
		{
			for(vector<T>::size_type i = 0; i < vec.size(); ++i)
			{
				cout << vec[i] << " ";
			}
			cout << endl;
		}

		template <typename T>
		static vector<vector<T > > createVectorOfVector(T *arr, int l1, int l2)
		{
			vector<vector<T> > vec(l1, vector<T>(l2));
			for(int i=0;i<l1;++i)
				for(int j=0;j<l2;++j)
					vec[i][j] = arr[i*l2+j];

			return vec;
		}

		template <typename T>
		static void printVectorOfVector(const vector<vector<T> > &vecOfVec)
		{
			for(vector<vector<T> >::size_type i=0;i<vecOfVec.size();++i)
			{
				printVector(vecOfVec[i]);
			}
			cout << endl;
		}

		template <typename T>
		static list<T> createList(T arr[], int len)
		{
			list<int> li;
			for(int i=0;i<len;++i)
			{
				li.push_back(arr[i]);
			}

			return li;
		}

		static void printList(const list<int> &li)
		{
			for(list<int>::const_iterator const_itr = li.begin(); const_itr != li.end(); ++const_itr)
			{
				cout << *const_itr << " ";
			}
			cout << endl;
		}

		static void printList(ListNode *head)
		{
			while(head)
			{
				cout << head->val << endl;
				head = head->next;
			}
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

		static void fileCopy(string &source, string &destination)
		{
			/*
			// copy file?
			// invalid file path, invalid file path
			// valid file path, invalid file path
			// valid file path, valid file path
				-> permission?
				-> storage?
				-> calculate hash value to guarantee file not corrupted
			*/
		}

		/*static void testArrayToLinkedList()
		{
			int arr[16] = {1, 3,4,5,8,9,11,13,14,15,16,20, 23,30,31,32};
			vector<int> vec = Utility::createVector<int>(arr,16);
			list<vector<int> >li;
			MSAlgorithm::arrayToLinkedList(vec, li);

			for(list<vector<int> >::const_iterator i = li.begin(); i != li.end(); ++i)
			{
				Utility::printVector( *i );
			}			
		}*/

		static int kthElementinSortedMatrix(int matrix[3][4], int width, int height, int k)
		{
			vector<int> cols(height);
			for(int i=0;i<cols.size();++i)
			{
				cols[i] = 0;
			}

			int indexX, indexY;
			for(int i=0;i<k;++i)
			{
				int mini = INT_MAX;
				for(int j=0;j<cols.size();++j)
				{
					if(cols[j] < width && mini > matrix[j][cols[j]])
					{
						mini = matrix[j][cols[j]];
						indexX = j;
						indexY = cols[j];
					}
				}
				cols[indexX]++;
			}

			return matrix[indexX][indexY];
		}

		static void TestKthElementinSortedMatrix()
		{
			int a[3][4] = {2, 5, 8, 10
				, 4, 7, 9, 12
				, 6, 15, 20, 22};
			cout << kthElementinSortedMatrix(a, 4, 3, 5);
		}

		static void sortZeroToSomeNumber(const vector<int> &source, vector<int> &dest, int num)
		{
			dest.resize(source.size());
			vector<int> vec(num,0);
			for(vector<int>::size_type idx = 0;idx<source.size();++idx)
			{
				vec[source[idx]]++;
			}
			for(vector<int>::size_type idx = 0, dest_idx = 0; idx<vec.size();++idx)
			{
				while(vec[idx]!=0)
				{
					dest[dest_idx++] = idx;
					vec[idx] --;
				}
			}
		}

		static void findTwoNumsSumToValue(const vector<int> &vec, int value)
		{
			map<int, int> number_map;
			for(vector<int>::size_type idx = 0; idx<vec.size();++idx)
			{
				int temp = value - vec[idx];
				map<int,int>::iterator itr = number_map.find(temp);
				if(itr!=number_map.end())
				{
					cout << temp << " " << vec[idx] << endl;
					if((*itr).second == 1)
					{
						number_map.erase(itr);
					}
					else
					{
						(*itr).second--;
					}
				}
				else
				{
					number_map[vec[idx]]++;
				}
			}
		}

		static void linkedListIntersect(const list<int> &listA,const list<int> &listB, list<int> &result)
		{
			list<int>::const_iterator itrA = listA.begin();
			list<int>::const_iterator itrB = listB.begin();
			result.clear();

			while(true)
			{
				if( (*itrA) > (*itrB) )
				{
					itrB++;
				}
				else if( (*itrA) < (*itrB) )
				{
					itrA++;
				}
				else
				{
					result.push_back((*itrA));
					itrA++;
					itrB++;
				}

				if( itrA == listA.end() || itrB == listB.end() )
				{
					return;
				}
			}
		}

		static void sumListAsNumber(const list<int> &first, const list<int> &second, list<int> &result)
		{
			result.clear();

			list<int>::const_iterator itrA = first.begin();
			list<int>::const_iterator itrB = second.begin();
			int inc = 0;
			while(true)
			{
				if(itrA == first.end() || itrB == second.end())
				{
					break;
				}

				int temp = (*itrA) + (*itrB) + inc;
				result.push_back(temp%10);
				inc = temp / 10;

				itrA++;
				itrB++;
			}

			if( itrA == first.end() && itrB == second.end())
			{
				if(inc)
					result.push_back(inc);
			}
			else
			{
				list<int>::const_iterator itr = itrA == first.end()?itrB:itrA;
				list<int>::const_iterator itrEnd = itrA == first.end()?second.end():first.end();
				while(true)
				{
					int temp = (*itr) + inc;
					result.push_back(temp%10);
					inc = temp/10;
					itr++;
					if(inc == 0)
					{
						result.insert(result.end(), itr,itrEnd);
						break;
					}
					if(itr==itrEnd)
					{
						result.push_back(inc);
						break;
					}
				}
			}
		}

		static void sortByNegativityZeroPositivity(const vector<int> &src, vector<int> &dest)
		{
			dest.resize(src.size());
			dest.assign(src.size(), 0);
			vector<int>::size_type leftIndex = 0;
			vector<int>::size_type rightIndex = dest.size()-1;

			for(vector<int>::size_type i = 0;i<src.size();++i)
			{
				if(src[i] < 0)
				{
					dest[leftIndex++] = src[i];
				}
				else if(src[i]>0)
				{
					dest[rightIndex--] = src[i];
				}
			}
		}

		static LinkedListNode<char> * findCircularLinkedList(LinkedListNode<char> *node)
		{
			if(node->next == NULL)
				return NULL;
			LinkedListNode<char> *n1 = node;
			LinkedListNode<char> *n2 = node;

			while(n1 != n2)
			{
				if(n1->next != NULL)
					n1 = n1->next;
				else
					return NULL;
				for(int i=0;i<2;++i)
					if(n2->next)
						n2 = n2->next;
					else
						return NULL;
			}

			n1 = node;
			while(n1!=n2)
			{
				n1 = n1->next;
				n2 = n2->next;
			}

			return n1;
		}

		static void convertToAlphabet(long long x)
		{
			if(x > 0)
			{
				--x;
				convertToAlphabet(x/26);
				cout << (char)((x%26)+'A');
			}
		}

		// assuming the value in the vector it's in base 10
		// assuming the higher digit is in lower index
		static void convertToAlphabet(vector<int> &vec, string &result)
		{
			result.clear();
			if(vec.size()==0)
				return;
			int value = 0;
			for(vector<int>::size_type idx = 0; idx<vec.size();)
			{
				int tmp_val = value / 26;
				if(tmp_val < 26)
				{
					value = value * 10 + vec[idx];
					++idx;
				}
				else
				{
					value--;
					result.push_back((value%26) + 'A');
					value = value/26;
				}
			}
			while(value > 0)
			{
				value --;
				result.push_back((value%26)+'A');
				value = value/26;
			}

			reverse(result.begin(), result.end());
		}

		static void findMinimumRectangle(vector<vector<int> > &vec)
		{
			pair<int,int> top_left(INT_MAX, INT_MAX), bottom_right(-1,-1);
			
			// top
			for(vector<vector<int> >::size_type i = 0; i < vec.size();++i)
			{
				for(vector<int>::size_type j=0;j<vec[0].size();++j)
				{
					if(vec[i][j] == 1)
					{
						if(i<top_left.first)
						{
							top_left.first = i;
							break;
						}

					}
				}
				if(top_left.first != INT_MAX)
					break;
			}

			// left
			for(vector<int>::size_type j=0;j<vec[0].size();++j)
			{
				for(vector<vector<int> >::size_type i = 0; i < vec.size();++i)
				{
					if(vec[i][j] == 1)
					{
						top_left.second = j;
						break;
					}
				}
				if(top_left.second != INT_MAX)
					break;
			}
			
			// bottom
			for(vector<vector<int> >::size_type i = vec.size()-1; i > -1; --i)
			{
				for(vector<int>::size_type j = vec[0].size()-1; j > -1; --j)
				{
					if(vec[i][j] == 1)
					{
						bottom_right.first = i;
						break;
					}
				}
				if(bottom_right.first != INT_MAX)
					break;
			}

			// right
			for(vector<int>::size_type j = vec[0].size()-1; j > -1; --j)
			{
				for(vector<vector<int> >::size_type i = 0; i < vec.size();++i)
				{
					if(vec[i][j] == 1)
					{
						bottom_right.second = j;
						break;
					}
				}
				if(bottom_right.second != INT_MAX)
					break;
			}

			cout << "top: " << top_left.first 
				<< " left: " << top_left.second
				<< " bottom: " << bottom_right.first
				<< " right: " << bottom_right.second << endl;
		}

		static void integerToLinkedList(int value, list<int> &result)
		{
			result.clear();
			if(value == 0)
			{
				result.push_back(value);
				return;
			}
			bool flag = false;
			if(value < 0)
			{
				flag = true;
				value = -value;
			}
			while(value!= 0)
			{
				result.push_front(value%10);
				value /=  10;
			}
			if(flag)
				result.push_front(-1);
		}

		static int linkedListToInteger(const list<int> & input)
		{
			if(input.size() == 0)
			{
				return 0;
			}
			bool flag =false;
			int value = 0;
			for(list<int>::const_iterator c_itr = input.begin(); c_itr!=input.end();++c_itr)
			{
				if((*c_itr)==-1)
				{
					flag = true;
				}
				else
				{
					value = value * 10 + (*c_itr);
				}
			}
			return flag?-value:value;
		}

		static void sumLinkedList(const list<int> &listA, const list<int> &listB, list<int> &result)
		{
			int valueA = linkedListToInteger(listA);
			int valueB = linkedListToInteger(listB);
			integerToLinkedList(valueA+valueB, result);
		}
	};
}

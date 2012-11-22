#include "stdafx.h"
#include "CppUnitTest.h"
#include "AlgorithmImpl.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmImpl
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestArrayToListSeq)
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
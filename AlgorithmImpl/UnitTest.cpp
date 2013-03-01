#include "stdafx.h"
#include "CppUnitTest.h"
#include "AlgorithmImpl.h"
#include "BinaryTree.h"
#include "BigInteger.h"
#include "BitOperations.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmImpl
{
	TEST_CLASS(UnitTest)
	{
	public:
		/*
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


		TEST_METHOD(TestBinaryTreePrint)
		{
			BinaryTree *d = new BinaryTree(NULL,NULL, 'd');
			BinaryTree *e = new BinaryTree(NULL,NULL, 'e');
			BinaryTree *f = new BinaryTree(NULL,NULL, 'f');
			BinaryTree *g = new BinaryTree(NULL,NULL, 'g');
			BinaryTree *b = new BinaryTree(d,e, 'b');
			BinaryTree *c = new BinaryTree(f,g, 'c');
			BinaryTree *a = new BinaryTree(b,c, 'a');
			BinaryTree::printInRotatingOrder(a);
		}
		*/
		TEST_METHOD(TEstBigIntegerAdd)
		{
			BigInteger integer1("2345");
			BigInteger integer2("8765");

			BigInteger integer3(integer1.add(integer2));

			Assert::AreEqual(integer3.getValue(), string("11110"));

			integer1 = BigInteger("-2345");
			integer2 = BigInteger("2345");
			integer3 = integer1.add(integer2);
			Assert::AreEqual(integer3.getValue(), string("0"));

			integer1 = BigInteger(23456);
			integer2 = BigInteger("-45678874234212");
			integer3 = integer1.add(integer2);
			Assert::AreEqual(integer3.getValue(),string("-45678874210756"));

			integer1 = BigInteger(-23456);
			integer2 = BigInteger("-45678874234212");
			integer3 = integer1.add(integer2);
			Assert::AreEqual(integer3.getValue(),string("-45678874257668"));

			integer1 = BigInteger(-23456);
			integer2 = BigInteger("45678874234212");
			integer3 = integer1.add(integer2);
			Assert::AreEqual(integer3.getValue(),string("45678874210756"));

			integer1 = BigInteger(23456);
			integer2 = BigInteger("45678874234212");
			integer3 = integer1.add(integer2);
			Assert::AreEqual(integer3.getValue(),string("45678874257668"));
		}

		TEST_METHOD(TestBigIntegerSubstract)
		{
			BigInteger integer1, integer2, integer3;

			integer1 = BigInteger(23456);
			integer2 = BigInteger("45678874234212");
			integer3 = integer1.substract(integer2);
			Assert::AreEqual(integer3.getValue(),string("-45678874210756"));

			integer1 = BigInteger(-23456);
			integer2 = BigInteger("-45678874234212");
			integer3 = integer1.substract(integer2);
			Assert::AreEqual(integer3.getValue(),string("45678874210756"));

			integer1 = BigInteger("45678874234212");
			integer2 = BigInteger(23456);
			integer3 = integer1.substract(integer2);
			Assert::AreEqual(integer3.getValue(),string("45678874210756"));

			integer1 = BigInteger(23457);
			integer2 = BigInteger(23456);
			integer3 = integer1.substract(integer2);
			Assert::AreEqual(integer3.getValue(),string("1"));
		}

		TEST_METHOD( TestBitCount )
		{
			int v = 5;
			Assert::AreEqual(BitOperation::bitCount(v), 2);
			v = 1314520;
			Assert::AreEqual(BitOperation::bitCount(v), 9);
			v = 0;
			Assert::AreEqual(BitOperation::bitCount(v), 0);
			v = INT_MIN;
			Assert::AreEqual(BitOperation::bitCount(v), 2);
		}
	};
}

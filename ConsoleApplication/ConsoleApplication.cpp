// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#pragma comment(lib,"AlgorithmImpl.lib")

#include "stdafx.h"

#include "AlgorithmImpl.h"
#include "BinaryTree.h"
#include "LinkedList.h"
#include "BigInteger.h"
using namespace AlgorithmImpl;

int _tmain(int argc, _TCHAR* argv[])
{
	BigInteger integer1(23456);
	BigInteger integer2(45678);

	BigInteger integer3(integer1.add(integer2));

	integer3.print();

	integer1 = BigInteger("-2345");
	integer2 = BigInteger("2345");
	integer3 = BigInteger(integer1.add(integer2));
	integer3.print();

	integer1 = BigInteger(23456);
	integer2 = BigInteger("45678874234212");
	integer3 = integer1.add(integer2);
	integer3.print();

	integer1 = BigInteger(-23456);
	integer2 = BigInteger("-45678874234212");
	integer3 = integer1.add(integer2);
	integer3.print();

	integer1 = BigInteger(23456);
	integer2 = BigInteger("-45678874234212");
	integer3 = integer1.add(integer2);
	integer3.print();

	cout << endl;

	integer1 = BigInteger(23456);
	integer2 = BigInteger("45678874234212");
	integer3 = integer1.substract(integer2);
	integer3.print();

	integer1 = BigInteger(-23456);
	integer2 = BigInteger("-45678874234212");
	integer3 = integer1.substract(integer2);
	integer3.print();

	integer1 = BigInteger("45678874234212");
	integer2 = BigInteger(23456);
	integer3 = integer1.substract(integer2);
	integer3.print();

	integer1 = BigInteger(23457);
	integer2 = BigInteger(23456);
	integer3 = integer1.substract(integer2);
	integer3.print();

	getchar();
	return 0;
}


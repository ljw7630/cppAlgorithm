// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#pragma comment(lib,"AlgorithmImpl.lib")

#include "stdafx.h"

#include "AlgorithmImpl.h"
using namespace AlgorithmImpl;

int _tmain(int argc, _TCHAR* argv[])
{
	MSAlgorithm::testArrayToLinkedList();

	getchar();
	return 0;
}


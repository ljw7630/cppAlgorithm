#include "AlgorithmImpl.h"
#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H
namespace AlgorithmImpl{

	struct ListNode{
		int val;
		ListNode *next;
		ListNode (int x):val(x),next(NULL){}
	};
}

#endif
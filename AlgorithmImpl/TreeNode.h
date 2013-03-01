#include "AlgorithmImpl.h"
#pragma once
#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif
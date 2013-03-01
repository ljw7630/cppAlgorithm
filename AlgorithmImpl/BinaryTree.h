#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

namespace AlgorithmImpl
{
	class BinaryTree
	{
	public:
		char value;
		BinaryTree *leftChild;
		BinaryTree *rightChild;

		BinaryTree(BinaryTree *left, BinaryTree *right, char value)
		{
			this->leftChild = left;
			this->rightChild = right;
			this->value = value;
		}

		~BinaryTree()
		{
			//recursiveDelete(this);
		}

		void recursiveDelete(BinaryTree * &node)
		{
			if(node == NULL)  // i don't think this will happen
				return;
			if(NULL != node->leftChild)
				recursiveDelete(node->leftChild);
			if(NULL != node->rightChild)
				recursiveDelete(node->rightChild);
			delete node;
		}

		BinaryTree(char value, BinaryTree * left, BinaryTree * right)
		{
			this->value = value;
			this->leftChild = left;
			this->rightChild = right;
		}

		static void printInRotatingOrder(BinaryTree * currentNode)
		{
			stack<BinaryTree *> leftStack;
			stack<BinaryTree *> rightStack;
			stack<BinaryTree *> * stack1 = &leftStack;
			stack<BinaryTree *> * stack2 = &rightStack;
			leftStack.push(currentNode);

			while(stack1->size() || stack2->size())
			{
				BinaryTree * node = stack1->top();
				stack1->pop();
				cout << node->value << " ";
				BinaryTree * childNode1;
				BinaryTree * childNode2;
				if(stack1 == &leftStack)
				{
					childNode1 = node->leftChild;
					childNode2 = node->rightChild;
				}
				else
				{
					childNode2 = node->leftChild;
					childNode1 = node->rightChild;				
				}
				if(childNode1!=NULL)
					stack2->push(childNode1);

				if(childNode2!=NULL)
					stack2->push(childNode2);
				if(!stack1->size())
					swap(stack1, stack2);
			}

		}

		static void TestBinaryTreePrint()
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
	};
}

#endif
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace AlgorithmImpl
{
	template <typename T>
	class LinkedListNode
	{
	public:
		T value;
		LinkedListNode<T> * next;

		LinkedListNode(T value, LinkedListNode<T> *next)
		{
			this->value = value;
			this->next = next;
		}

		static void print(LinkedListNode<T> *node)
		{
			while(node->next)
			{
				cout << node->value << " ";
			}
			cout << endl;
		}
	};
}

#endif
#include <iostream>
#include "linkedlist.h"

template <class T> class LinkedList
{
    LinkedListNode<T> *head, *tail;

public:
	LinkedList() {
		head = NULL;
	}

	~LinkedList(){

	}

};
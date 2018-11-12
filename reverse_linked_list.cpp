#include <iostream>
#include <vector>
#include "linkedlist.h"
using std::cout;
using std::endl;

LinkedListNode* reverse_iterative(LinkedListNode* head) {
  //TODO: Write - Your - Code
  return head;
}

int main(int argc, char *argv[])
{
	int key = atoi(argv[1]);
	std::vector<int> v1 = {1, 2, 3, 4 , 5};
	LinkedListNode* list_head = LinkedList::create_linked_list(v1);
	
	cout << "Original List: " << LinkedList::display(list_head); << endl;
	//list_head = reverse_iterative(list_head);
	//cout << "Key: "<< key << " found at: "<< index << endl;

	return 1;
}
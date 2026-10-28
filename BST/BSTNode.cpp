#include "BSTNode.h"
#include "BST.h"
#include <iostream>

int main()
{
	BST bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(2);
	bst.insert(4);
	bst.insert(1);
	bst.insert(6);
	bst.insert(7);
	bst.insert(9);

	bst.print();

	std::cout << std::endl;
	std::cout << "find(4): " << (bst.find(4) ? "true" : "false") << std::endl;
	std::cout << "find(10): " << (bst.find(10) ? "true" : "false") << std::endl;
	std::cout << "countNodes(): " << bst.countNodes() << std::endl;
	std::cout << "countLeaves(): " << bst.countLeaves() << std::endl;

	int toRemove[] = { 4, 2, 5, 10, 5 };
	for (int key : toRemove) {
		std::cout << std::endl << "remove(" << key << "): " << (bst.remove(key) ? "true" : "false") << std::endl;
		bst.print();
	}

	return EXIT_SUCCESS;
}

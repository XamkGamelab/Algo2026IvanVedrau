#pragma once
#include "BSTNode.h"

class BST
{
public:
	//constructor: sets root node to null
	BST() { pRoot = nullptr; }

	bool isEmpty() {return pRoot == nullptr;}
	
	void insert(int key);

private:
	//pointer to the root-node of the BST
	BSTNode* pRoot;
};


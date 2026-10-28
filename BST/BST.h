#pragma once
#include "BSTNode.h"

class BST
{
public:
	//constructor: sets root node to null
	BST() { pRoot = nullptr; }

	bool isEmpty() {return pRoot == nullptr;}
	
	void insert(int key);
	void print();
	bool find(int key);
	int countNodes();
	int countLeaves();
	bool remove(int key);

private:
	void print(BSTNode* node, int depth);
	int countNodes(BSTNode* node);
	int countLeaves(BSTNode* node);

	//pointer to the root-node of the BST
	BSTNode* pRoot;
};


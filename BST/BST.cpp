
#include <iostream>
#include "BST.h"

//INSERTS SMALLER VALUES LEFT AND EQUAL VALUES RIGHT
void BST::insert(int key) {

	BSTNode* pNewNode = new BSTNode(key);

	if (isEmpty()) {
		// set the new node with key value as the root
		pRoot = pNewNode;
		return;
	}

	else {
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot;
		while (pCandidate != nullptr) {
			pCurrent = pCandidate;

			if (pNewNode->key < pCurrent->key)
				pCandidate = pCurrent->left;
			else
				pCandidate = pCurrent->right;
		}

		if(pNewNode->key < pCurrent->key)
			pCurrent->left = pNewNode;
		else
			pCurrent->right = pNewNode;
	}


}

bool BST::remove(int key) {
	// finds the node and its parent first
	BSTNode* pParent = nullptr;
	BSTNode* pCurrent = pRoot;
	while (pCurrent != nullptr && pCurrent->key != key) {
		pParent = pCurrent;
		if (key < pCurrent->key)
			pCurrent = pCurrent->left;
		else
			pCurrent = pCurrent->right;
	}

	if (pCurrent == nullptr)
		return false; 

	//if thre are two children: copy the smallest key of the right subtree here, then delete that smallest node instead (it has no left child)
	if (pCurrent->left != nullptr && pCurrent->right != nullptr) {
		BSTNode* pMinParent = pCurrent;
		BSTNode* pMin = pCurrent->right;
		while (pMin->left != nullptr) {
			pMinParent = pMin;
			pMin = pMin->left;
		}
		pCurrent->key = pMin->key;
		pParent = pMinParent;
		pCurrent = pMin;
	}

	// now pCurrent has at most one child: that child moves one step up
	BSTNode* pChild;
	if (pCurrent->left != nullptr)
		pChild = pCurrent->left;
	else
		pChild = pCurrent->right;

	if (pParent == nullptr)
		pRoot = pChild;
	else if (pParent->left == pCurrent)
		pParent->left = pChild;
	else
		pParent->right = pChild;

	delete pCurrent;
	return true;
}

void BST::print() {
	print(pRoot, 0);
}

// Prints in somewhat tree-like manner. It is rotated 90 degrees so it goes smaller to thhe bottom and higher to the top
void BST::print(BSTNode* node, int depth) {
	if (node == nullptr)
		return;

	print(node->right, depth + 1);
	for (int i = 0; i < depth; i++)
		std::cout << "    ";
	std::cout << node->key << std::endl;
	print(node->left, depth + 1);
}

bool BST::find(int key) {
	BSTNode* pCurrent = pRoot;
	while (pCurrent != nullptr) {
		if (key == pCurrent->key)
			return true;

		if (key < pCurrent->key)
			pCurrent = pCurrent->left;
		else
			pCurrent = pCurrent->right;
	}
	return false;
}

int BST::countNodes() {
	return countNodes(pRoot);
}

int BST::countNodes(BSTNode* node) {
	if (node == nullptr)
		return 0;
	return countNodes(node->left) + countNodes(node->right) + 1;
}

int BST::countLeaves() {
	return countLeaves(pRoot);
}

int BST::countLeaves(BSTNode* node) {
	if (node == nullptr)
		return 0;
	if (node->left == nullptr && node->right == nullptr)
		return 1;
	return countLeaves(node->left) + countLeaves(node->right);
}

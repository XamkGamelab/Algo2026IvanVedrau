
#include <iostream>
#include "BST.h"

//INSERTS SMALLER VALUES LEFT AND EQUAL VALUES RIGHT
void BST::insert(int key) {

	BSTNode* pNewNode = new BSTNode(key);
	if (isEmpty()) {
		// set the new node with key value as the root
		BSTNode* pNewNode = new BSTNode(key);
		pRoot = pNewNode;
		return;
	}

	else {
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot;
		while (pCandidate != nullptr) {
			pCurrent = pCandidate;

			if (pNewNode->key < pCurrent->key)
				pCandidate = pCurrent->pLeft;
			else
				pCandidate = pCurrent->pRight;
		}

		if(pNewNode->key < pCurrent->key)
			pCurrent->pLeft = pNewNode;
		else
			pCurrent->pRight = pNewNode;
	}
}

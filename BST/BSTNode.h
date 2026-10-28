#pragma once
class BSTNode {
public:
	int key;
	BSTNode* left;
	BSTNode* right;

	BSTNode() {
		key = -1;
		left = nullptr;
		right = nullptr;
	}

	//constructor with key value as parameter
	BSTNode(int value) {
		key = value;
		left = nullptr;
		right = nullptr;
	}
};

// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"
#include "LinkedLists.h"

bool LinkedList::IsEmpty() {
	return this->head == nullptr;
}

void LinkedList::Insert(int x) {
	Node* newNode = new Node{ x };

	newNode->next = this->head;
	this->head = newNode;
}

void LinkedList::InsertEnd(int x) {
	Node* newNode = new Node{ x };

	if (IsEmpty()) {
		this->head = newNode;
	}

	else {
		//The list is not empty
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void LinkedList::Print() {
	Node* temp = head;

	while (temp != nullptr) {
		std::cout << temp->data << "->";
		temp = temp->next;
	
	}
	std::cout << "NULL" << std::endl;
}

bool LinkedList::Find(int x) {

	if (head == nullptr) {
		return false;
	}

	Node* temp = head;

	while (temp != nullptr) {
		if (temp->data == x) {
			std::cout << "Found" << std::endl;
			return true;
		}
		else
			temp = temp->next;
	}
	std::cout << "Not Found" << std::endl;
	return false;
}

bool LinkedList::Delete(int x) {

	if (head == nullptr) {
		return false;
	}

	if (head->data == x) {
		Node* toDelete = head;
		head = head->next;            
		delete toDelete;
		return true;
	}

	Node* prev = head;
	Node* curr = head->next;

	while (curr != nullptr) {
		if (curr->data == x) {
			prev->next = curr->next;
			delete curr;
			return true;
		}

		prev = curr;
		curr = curr->next;
		
	}
	return false;
}

void LinkedList::Reverse() {

	Node* prev = nullptr;
	Node* curr = head;

	while (curr != nullptr) {
		Node* next = curr->next;
		curr->next= prev; 
		prev = curr;
		curr = next;
	}

	head = prev;
}

/*

int main()
{

	LinkedList ll;

	ll.InsertEnd(2);
	ll.InsertEnd(3);
	ll.Insert(1);
	ll.Insert(0);

	ll.Reverse();
	ll.Print();

	ll.Find(4);
	ll.Delete(3);

	ll.Reverse();
	ll.Print();

	ll.Delete(0);     
	ll.Delete(99);    
	ll.Delete(1);
	ll.Delete(2);     
	ll.Print();       



	std::cout << "IsEmpty(): " << ll.IsEmpty() << '\n'; 
	return EXIT_SUCCESS;
}
*/
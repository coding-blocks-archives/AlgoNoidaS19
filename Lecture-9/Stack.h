#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class Stack{
	node<T>* head;
public:

	Stack(){
		head = NULL;
	}

	void push(T d){
		// Insertion at beg in LL
		node<T> *n = new node<T>(d);
		n->next = head;
		head =n;
	}
	void pop(){
		// Deletion at beg in LL
		if(head!=NULL){
			node<T>* n = head;
			head = head->next;
			delete n;
		}
	}
	T top(){
		return head->data;
	}
	bool empty(){
		return head == NULL;
	}
};
#endif

//*************************************************//
//	Project 1											 							   //
//	Aaron Moton					        June 5th, 2016		 //
//	Luis Dominguez																 //
//*************************************************//

#include "DoubleNode.h"
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

template <class T>
class DoublyLinkedList {
private:
  DoubleNode<T>* head;
  DoubleNode<T>* tail;
  int sz;
public:
  DoublyLinkedList():head(NULL), tail(NULL), sz(0){
  }

  ~DoublyLinkedList() {
	  DoubleNode<T> *current = head;
	  DoubleNode<T> *next;

	  while (current != NULL) {
		  next = current->next;
		  delete current;
		  current = next;
	  }

  }

  //Accessors
  int size() const { return sz; };
  bool isEmpty() const { return sz == 0; };
  T front() const {	  //Retrieves object stored in the head node.
	  if (isEmpty())
		  throw underflow_error("List is empty.");
	  else
		  return head->data;
  }

  T back() const {	 //Retrieves object stored in the tail node.
	  if (isEmpty())
		  throw underflow_error("List is empty.");
	  else
		return tail->data;
  }

  DoubleNode<T>* getHead() const { return head; } //Returns pointer to head of list
  DoubleNode<T>* getTail() const { return tail; } //Returns pointer to tail of list

  //Returns amount of nodes holding that data value
  int count(T const &nData) const {
    int c = 0;
    DoubleNode<T>* p = head;
    while(p != 0){
      if(p->data == nData)
        c++;
      p = p->next;
    }
    return c;
  }

  //Mutators

  //Adds new node to the front of list
  void push_front(T const &nData) {
    DoubleNode<T> *Node;
    if(isEmpty()) {
      Node = new DoubleNode<T>(nData, NULL, NULL);
      head = Node;
      tail = Node;
      sz++;
    }
    else{
      Node = new DoubleNode<T>(nData, NULL, head);
      head->prev = Node;
      head = Node;
      sz++;
    }
  }

  //Adds new node to the end of list
  void push_back(T const &nData) {
    DoubleNode<T>* Node;
    if(isEmpty()) {
      Node = new DoubleNode<T>(nData, NULL, NULL);
      head = Node;
      tail = Node;
      sz++;
    }
    else{
      Node = new DoubleNode<T>(nData, tail, NULL);
      tail->next = Node;
      tail = Node;
      sz++;
    }
  }

  //Delete the node at the front of list
  T pop_front() {
	  if (isEmpty())
		  throw underflow_error("List is empty.");
	  else {
		  assert(!isEmpty());
		  T dat = head->data; // Gets data from node pre-pop
		  DoubleNode<T>* p;        // Navigator pointer
		  if (head != tail) {     //If head and tail are not the same
			  p = head->next;     // Navigate to the second node
			  p->prev = 0;        // Set the second node's prev to null
			  delete head;         // Free the first node
			  head = p;           // Second node becomes first node
			  sz--;
		  }
		  else {
			  delete head; // Frees head and tail memory
			  sz--;
		  }

		  return dat;
	  }
  }

  void Display() {
    DoubleNode<T>* p = head;
    if(isEmpty())
      cout << "List is empty." << endl;
    else
    while(p != NULL){
      cout << p->data << endl;
      p = p->next;
    }
  }

  int erase(T const &nData) {
	  if (isEmpty()) {
		  cerr << endl << "List is empty." << endl;
		  return 0;
	  }

	  DoubleNode<T>* prev;
	  DoubleNode<T>* curr = head;
	  DoubleNode<T>* lead;
	  int cnt = 0;
	  if (head == tail && head->data == nData) {
		  delete head;
		  head = NULL;
		  tail = NULL;
		  cnt++;
		  sz--;
		  return cnt;
	  }

	  while (curr != NULL) {
		  if (curr == head && curr->data == nData) {
			  curr = head->next;
			  delete head;
			  head = curr;
			  curr->prev = NULL;
			  cnt++;
			  sz--;
		  }
		  else if (curr == tail && curr->data == nData) {
			  curr = tail->prev;
			  delete tail;
			  tail = curr;
			  curr->next = NULL;
			  cnt++;
			  sz--;
			  return cnt;
		  }
		  else if (curr->data == nData) {
			  prev = curr->prev;
			  lead = curr->next;
			  delete curr;
			  prev->next = lead;
			  lead->prev = prev;

			  curr = lead;
			  cnt++;
			  sz--;
		  }
		  else
			  curr = curr->next;
	  }

	  return cnt;

}
};

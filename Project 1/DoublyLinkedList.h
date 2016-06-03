#include "DoubleNode.h"
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class DoublyLinkedList {
private:
  DoubleNode<T>* head;
  DoubleNode<T>* tail;
  int sz;
public:
  DoublyLinkedList():head(0), tail(0), sz(0){
  }

  ~DoublyLinkedList() {
    DoubleNode<T>* p = head;
    if (p == NULL)
    {}
    else {
    DoubleNode<T>* q = p->next;
    while(p != NULL){
      delete p;
      p = q;
      if(q->next != NULL)
        q = q->next;
      }
    }
  }

  //Accessors
  int size() const { return sz; };
  bool isEmpty() const { return sz == 0; };
  T front() const { return head->data;} //Retrieves object stored in the head node.
  T back() const { return tail->data; } //Retrieves object stored in the tail node.
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
    DoubleNode<T>* Node;
    if(isEmpty()) {
      Node = new DoubleNode<T>(nData, 0, 0);
      head = Node;
      tail = Node;
      sz++;
    }
    else{
      Node = new DoubleNode<T>(nData, 0, head);
      head->prev = Node;
      head = Node;
      sz++;
    }
  }

  //Adds new node to the end of list
  void push_back(T const &nData) {
    DoubleNode<T>* Node;
    if(isEmpty()) {
      Node = new DoubleNode<T>(nData, 0, 0);
      head = Node;
      tail = Node;
      sz++;
    }
    else{
      Node = new DoubleNode<T>(nData, tail, 0);
      tail->next = Node;
      tail = Node;
      sz++;
    }
  }

  //Delete the node at the front of list
  T pop_front() {
      assert(!isEmpty());
      T dat = head->data; // Gets data from node pre-pop
      DoubleNode<T>* p;        // Navigator pointer
      if(head != tail){     //If head and tail are not the same
        p = head->next;     // Navigate to the second node
        p->prev = 0;        // Set the second node's prev to null
        delete head;         // Free the first node
        head = p;           // Second node becomes first node
        sz--;
      }
      else{
        delete head;
        delete tail; // Frees head and tail memory
        sz--;
      }

      return dat;
  }

  void Display() {
    DoubleNode<T>* p = head;
    if(isEmpty())
      cout << "list is empty." << endl;
    else
    while(p != 0){
      cout << p->data << endl;
      p = p->next;
    }
  }

  int erase(T const &nData) {
    DoubleNode<T>* p = head;
    DoubleNode<T>* q;
    DoubleNode<T>* r;
    while(p != 0){
      if((p == head) && (p->data == nData)){
        p = head->next;
        p->prev = 0;
        delete head;
        head = p;
        sz--;
      }
      else if((p == tail) && (p->data == nData)){
        p = tail->prev;
        p->next = 0;
        delete tail;
        tail = p;
        sz--;
      }
      else if(p->data == nData){
        q = p->prev;
        r = p->next;
        q->next = r;
        r->prev = q;
        delete p;
        p = q;
        sz--;
      }

      p = p->next;
    }

}
};

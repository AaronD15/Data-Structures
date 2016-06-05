//*************************************************//
//	Project 1											 							   //
//	Aaron Moton					        June 5th, 2016		 //
//	Luis Dominguez																 //
//*************************************************//

#include <iostream>
#include <cassert>
using namespace std;

template <class T> class SingleNode {
private:
	T data;
	SingleNode * next;
	template <class U>
	friend class CyclicLinkedList;
public:
	SingleNode() :data(0), next(0) {}

	SingleNode(const T & data, SingleNode * next) {
		this->data = data;
		this->next = next;
	}
	T getData() const { return this->data; }
	SingleNode * getNext() const { return this->next; }

};

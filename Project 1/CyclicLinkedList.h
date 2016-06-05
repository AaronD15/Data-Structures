//*************************************************//
//	Project 1											 							   //
//	Aaron Moton					        June 5th, 2016		 //
//	Luis Dominguez																 //
//*************************************************//

#include "SingleNode.h"

template<class t> class CyclicLinkedList {
private:
	SingleNode<t> * head;
	SingleNode<t> * tail;
	int size;

public:
	CyclicLinkedList() :head(NULL), tail(NULL), size(0) {}

	~CyclicLinkedList() {
		SingleNode<t> *current = head;
		SingleNode<t> *next;

		while (current != NULL) {
			next = current->next;
			if (current == tail) {
				delete current;
				break;
			}
			delete current;
			current = next;
		}

	}

	int SIZE() const { return size; }
	bool empty() const { return size == 0; }
	t front() const {
		if(empty())
			throw underflow_error("List is empty.");
		else
			return head->data;
	}
	t back() const {
		if(empty())
			throw underflow_error("List is empty.");
		else
			return tail->data;
	}

	SingleNode<t> * HEAD() const { return head; }
	SingleNode<t> * TAIL() const { return tail; }

	int count(t const & data) const {
		if (size == 0)
		{
			cout << "List Empty" << endl;
			return 0;
		}
		int count = 0;
		SingleNode<t> *ptr = head;
		SingleNode<t> *ptr2 = tail;
		if (ptr == NULL) {
			cout << "List Empty" << endl;
			return -1;
		}
		if (ptr2->data == data) { count++; }
		while (ptr->next != head && ptr->next != NULL) {
			if (ptr->data == data) { count++; }
			ptr = ptr->next;
		}
		return count;

	}

	void push_front(t const & data) {
		SingleNode<t> *newSingleNode = new SingleNode<t>(data, head);
		head = newSingleNode;
		SingleNode<t> *ptr = head;
		if (tail == NULL) {
			tail = newSingleNode;
			size++;
		}
		else {
			tail->next = newSingleNode;
			while (ptr->next != head && ptr->next != NULL) {
				ptr = ptr->next;
			}
			tail = ptr;
			size++;
		}
	}

	void push_back(t const & data) {
		SingleNode<t> *newSingleNode = new SingleNode<t>(data, head);
		SingleNode<t> *ptr = head;
		if (ptr == NULL) {
			head = newSingleNode;
			tail = newSingleNode;
		}
		else if (ptr == tail)
		{
			ptr->next = newSingleNode;
			tail = newSingleNode;
		}
		else {
			while (ptr != tail && ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = newSingleNode;
			tail = newSingleNode;
		}
		size++;
	}

	void printList()const {
		if (size == 0)
		{
			cout << "List empty." << endl;
			return;
		}
		SingleNode<t> *ptr = head;
		cout << ptr->data << endl;
		ptr = ptr->next;
		while (ptr != head && ptr != NULL) {
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}

	t pop_front() {
		if (empty())
			throw underflow_error("List is empty.");
		else {
		SingleNode<t> *pop = head;
		SingleNode<t> *ptr = head;
		t popdata;

		head = ptr->next;
		tail->next = head;
		popdata = pop->data;
		delete pop;
		size--;
		return popdata;
		}
	}


	int erase(t const & data) {
		if (size == 0) {
			cerr << endl << "List empty" << endl;
			return 0;
		}
		SingleNode<t> * ptr = head->next;
		SingleNode<t> * prev = head;
		int count = 0;
		if (prev->data == data && size == 1)
		{
			delete prev;
			head = NULL;
			tail = NULL;
			size--;
			count++;
			return count;
		}
		else while (ptr != head) {
			if (prev->data == data) {
				head = prev->next;
				tail->next = head;
				delete prev;
				count++;
				size--;
			}
			else if (ptr->data == data) {
				if (ptr == tail) {
					delete ptr;
					ptr = head;
					tail = prev;
					tail->next = head;
				}
				else {
					prev->next = ptr->next;
					delete ptr;
					ptr = prev;
				}
				count++;
				size--;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		return count;
	}
};

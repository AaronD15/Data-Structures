#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class type>
class DynQueue {
private:
	type *Dqueue;
	int ihead;
	int itail;
	int count;
	int initialSize;
	int arraySize;

public:
	DynQueue(int n =13) : ihead(0), itail(-1), count(0) {
		cout << endl << "Please insert queue initial capacity: ";
		cin >> initialSize;
		if (n < 1)
			initialSize = 1;
		arraySize = initialSize;
		Dqueue = new type[arraySize];
	}
	~DynQueue() {
		delete[] Dqueue;
	}

	type front() const {
		if (empty()) throw underflow_error("Queue is empty.");
		else {
			return Dqueue[ihead];
		}
	}
	type back() const {
		if (empty()) throw underflow_error("Queue is empty.");
		else {
			return Dqueue[itail];
		}
	}
	int size() const { return count; }
	bool empty() const { return count == 0; }
	int capacity() const { return arraySize; }
	void display() {
	/*Array Implementation of Display
		if (!empty()) {
			int pos = 0;
			for (int i = ihead; i < count + ihead; i++) {
				cout << "Queue at [" << pos << "]: " << Dqueue[i] << endl;
				pos++;
			}
			cout << "Number of Elements in the Queue: " << count << endl;
			cout << "Queue Size : " << arraySize << endl;
		}

		else cout << "Queue is empty." << endl;*/

		//Display using enqueuing and dequeuing
		if (empty()) cout << "Queue is empty." << endl;
		else {
			type *temp = new type[arraySize];
			int oldSize = arraySize;
			int i = 0;
			int prevCount = count;
			type dequeued;
			while (true) {
					dequeued = dequeue();
					cout << dequeued << endl;
					temp[i] = dequeued;
					i++;
				if (i== prevCount) break;
			}
			count = prevCount;
			arraySize = oldSize;
			ihead = 0;
			itail = i -1;
			Dqueue = temp;
		}
	}

	void enqueue(type const & data) {
		if (count == arraySize){
			//Doubling Size
			int oldSize = arraySize;
			arraySize *= 2;
			type *temp = new type[arraySize];
			int tempHead = ihead;
			int i = 0;
			while (true) {
				temp[i] = Dqueue[tempHead];
				i++;
				tempHead++;
				if (tempHead == oldSize)
				{
					tempHead = 0;
				}
				if (count == i) {
					break;
				}
			}
			Dqueue = temp;
			ihead = 0;
			itail = i-1;
		}

		itail++;
		if (itail >= arraySize && count != arraySize) {
			itail = 0;
		}
		Dqueue[itail] = data;
		count++;
	}

	type dequeue() {
		if (empty()) throw underflow_error("Queue is empty.");
		else {
			type value = Dqueue[ihead];
			ihead++;
			count--;
			if (empty()) {
				ihead = 0;
				return value;
			}
			if (count <= arraySize/4 && arraySize > initialSize){
				//Halving Size
				int oldSize = arraySize;
				arraySize /= 2;
				type *temp = new type[arraySize];
				int tempHead = ihead;
				int i = 0;
				while (true) {
					temp[i] = Dqueue[tempHead];
					i++;
					tempHead++;
					if (tempHead == oldSize)
					{
						tempHead = 0;
					}
					if (count == i) {
						break;
					}
				}
				Dqueue = temp;
				ihead = 0;
				itail = i - 1;
			}
			return value;
		}
	}


	void clear() {
		//delete[] Dqueue;
		//arraySize = initialSize;
		//Dqueue = new type[initialSize];
		ihead = 0;
		itail = 0;
		count = 0;
		cout << "Queue Cleared" << endl;
		cout << "Number of Elements in the Queue: " << count << endl;
		cout << "Queue Size : " << arraySize << endl;
	}

	int erase(type const & data) {
		if (empty()) throw underflow_error("Queue is empty.");
		else {
			type *temp = new type[arraySize];
			int oldSize = arraySize;
			int i = 0;
			int erased = 0;
			int prevCount = count;
			type dequeued;
			while (true) {
				dequeued = dequeue();
				if (dequeued == data) {
					erased++;
				}
				else {
					temp[i] = dequeued;
					i++;
				}
				if (i + erased == prevCount) break;
			}
			count = prevCount - erased;
			arraySize = oldSize;

			Dqueue = temp;
			return erased;
		}
	}



};

#include "DoublyLinkedList.h"
#include "CyclicLinkedList.h"

int main() {
	int selection = 0;
	int op = 0;

	CyclicLinkedList<double> lst;
	DoublyLinkedList<double> list;
	bool flagc = false;
	bool flagd = false;

	while (true) {
		// Main Menu
		cout << "******Menu Program******" << endl;
		cout << "Please select an option." << endl;
		cout << "1. Cyclic Linked List." << endl;
		cout << "2. Doubly Linked List." << endl;
		cout << "3. Exit." << endl;
		cout << "--> ";
		cin >> selection;

		if (selection == 3)
			break;

		// Cyclic Linked List Selected
		else if (selection == 1) {

			cout << endl << "Cyclic Linked List" << endl;

			while (true) {

				cout << endl;
				cout << "Please select an option." << endl;
				cout << "1. Create List" << endl;
				cout << "2. Push Element" << endl;
				cout << "3. Pop the Top Element" << endl;
				cout << "4. Erase Elements" << endl;
				cout << "5. Count" << endl;
				cout << "6. Size" << endl;
				cout << "7. Print List" << endl;
				cout << "8. Back to Main Menu" << endl;
				cout << "--> ";
				cin >> op;

				if (op == 8) break;
				else if (op == 1) {
					if(flagc != true) {
						flagc = true;
						cout << endl << "List created." << endl;
					}
					else
						cout << endl << "List already exists." << endl;
				}
				else if (op == 2) {
					if (!flagc) {
						cerr << endl << "Cannot insert element. List has not been created yet." << endl;
					}
					else {
						double data;
						cout << endl << "Enter value to be pushed" << endl;
						cin >> data;
						int op_i = 0;
						cout << endl << "Do you want push element in the front or the back ?(1.Front, 2.Back)\n-->";
						cin >> op_i;
						if (op_i == 1) {
							lst.push_front(data);
						}
						else if (op_i == 2) {
							lst.push_back(data);
						}
						else cout << endl << "Invalid input" << endl;
					}
				}
				else if (op == 3) {
					if (!flagc) {
						cerr << endl << "Cannot pop element. List has not been created yet." << endl;
					}
					else {
						double popped = lst.pop_front();
						cout << "The popped value was " << popped << endl;
					}
				}

				else if (op == 4) {
					if (!flagc) {
						cerr << endl << "Cannot erase element. List has not been created yet." << endl;
					}
					else {

						double data;
						int erased;
						cout << "Enter value to be erased" << endl;
						cin >> data;
						erased = lst.erase(data);
						cout << erased << " element(s) deleted\n";
					}
				}

				else if (op == 5) {
					if (!flagc) {
						cerr << endl << "Cannot count elements. List has not been created yet." << endl;
					}
					double data;
					int counted;
					cout << "Enter value to count" << endl;
					cin >> data;
					counted = lst.count(data);
					cout << counted << " element(s) found\n";
				}
				else if (op == 6) {
					if (!flagc) {
						cerr << endl << "List has not been created yet." << endl;
					}
					cout << lst.SIZE() << " element(s) in the list." << endl;
				}
				else if (op == 7) {
					if (!flagc) {
						cerr << endl << "Cannot print the list. List has not been created yet." << endl;
					}
					else {
						cout << endl;
						lst.printList();
					}
				}
			}
		}


		// Doubly Linked List Selected
		else if (selection == 2) {
			cout << endl;
			cout << "Doubly Linked List" << endl;

			while (true) {

				cout << endl;
				cout << "******Menu Program******" << endl;
				cout << "Please select an option." << endl;
				cout << "1. Create List" << endl;
				cout << "2. Push Front" << endl;
				cout << "3. Push Back" << endl;
				cout << "4. Pop Front" << endl;
				cout << "5. Count" << endl;
				cout << "6. Size" << endl;
				cout << "7. Erase" << endl;
				cout << "8. Display" << endl;
				cout << "9. Back to Main Menu" << endl;
				cout << "--> ";

				cin >> op;
				if (op == 9)
					break;
				else if (op == 1) { // Create List
					if(flagd != true) {
						flagd = true;
						cout << endl << "List created." << endl;
					}
					else
						cout << endl << "List already exists." << endl;
				}
				else if (op == 2) { // Push Front
					if (!flagd)
						cout << endl << "Cannot insert element. List has not been created yet." << endl;
					else {
						double data;
						cout << endl << "Enter value to be pushed: ";
						cin >> data;
						list.push_front(data);
					}
				}
				else if (op == 3) { // Push Back
					if (!flagd)
						cout << endl << "Cannot insert element. List has not been created yet." << endl;
					else {
						double data;
						cout << endl << "Enter value to be pushed: ";
						cin >> data;
						list.push_back(data);
					}
				}
				else if (op == 4) { // Pop front
					if (!flagd)
						cout << endl << "Cannot pop element. List has not been created yet." << endl;
					else
						try {
						cout << list.pop_front() << " has been popped." << endl;
						}
					catch (const underflow_error& e) {
						cout << endl << e.what() << endl;
					}
				}
				else if (op == 5) { // Count
					if (!flagd)
						cout << endl << "Cannot count elements. List has not been created yet." << endl;
					else {
						double num;
						cout << endl << "Insert element to be counted: ";
						cin >> num;
						cout << endl << "There are " << list.count(num) << " elements of " << num << "." << endl;
					}
				}
				else if (op == 6) { // Size
					if (!flagd)
						cout << endl << "Cannot display size. List has not been created yet." << endl;
					else if (list.size() == 1)
							cout << endl << "List is " << list.size() << " element long." << endl;
						else
							cout << endl << "List is " << list.size() << " elements long." << endl;
				}
				else if (op == 7) { // Erase
					if (!flagd)
						cout << endl << "No elements to erase. List has not been created yet." << endl;
					else {
						double data;
						cout << endl << "Enter data of elements to erase: ";
						cin >> data;
						list.erase(data);
					}
				}
				else if (op == 8) { // Display
					if (!flagd)
						cout << endl << "Data cannot be displayed. List has not been created yet." << endl;
					else {
						cout << endl;
						list.Display();
					}
				}
				else
					cout << endl << "Invalid input." << endl;
			}
		}


		cout << endl << endl;
	}


	return 0;
}

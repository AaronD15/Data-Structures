#include "DoublyLinkedList.h"
#include "CyclicLinkedList.h"

int main(){
  int selection = 0;
  int op = 0;

  while(true) {
    // Main Menu
    cout << "******Menu Program******" << endl;
		cout << "Please select an option." << endl;
		cout << "1. Cyclic Linked List." << endl;
		cout << "2. Doubly Linked List." << endl;
		cout << "3. Exit." << endl;
		cout << "--> ";
		cin >> selection;

  if(selection == 3)
    break;

  // Cyclic Linked List Selected
  else if (selection == 1) {

    cout << endl << "Cyclic Linked List" << endl;
    bool flag = false;
    CyclicLinkedList<double> lst;

    while (true) {

      cout << endl;
      cout << "Please select an option." << endl;
      cout << "1. Create List." << endl;
      cout << "2. Push Element." << endl;
      cout << "3. Pop the Top Element." << endl;
      cout << "4. Erase Elements" << endl;
      cout << "5. Print List" << endl;
      cout << "6. Exit." << endl;
      cout << "--> ";
      cin >> op;

      if (op == 6) break;
      else if (op == 1) {
        flag = true;
        cout << endl << "List created." << endl;
      }
      else if (op == 2) {
        if (!flag) {
          cerr << endl << "Cannot insert element. List has not been created yet." << endl;
        }
        else {
          double data;
          cout << "Enter value to be pushed" << endl;
          cin >> data;
          int op_i = 0;
          cout << "Do you want push element in the front or the back ?(1.Front, 2.Back)\n-->";
          cin >> op_i;
          if (op_i == 1) {
            lst.push_front(data);
          }
          else if (op_i == 2) {
            lst.push_back(data);
          }
          else cout << "Invalid input";
        }
      }
      else if (op == 3) {
        if (!flag) {
          cerr << endl << "Cannot pop element. List has not been created yet." << endl;
        }
        else {
          double popped = lst.pop_front();
          cout << "The popped value was " << popped << endl;
        }
      }

      else if (op == 4) {
        if (!flag) {
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
        if (!flag) {
          cerr << endl << "Cannot print the list. List has not been created yet." << endl;
        }
        else {
          cout << endl;
          lst.printList();
        }
      }
      cout << endl << endl;
    }
  }


  // Doubly Linked List Selected
  else if (selection == 2) {
  cout << endl;
  cout  << "Doubly Linked List" << endl;

  int num;
  DoublyLinkedList<double> list;
  bool flag = false;
  while(true){

    cout << endl;
    cout << "******Menu Program******" << endl;
    cout << "Please select an option." << endl;
    cout << "1. Create List." << endl;
    cout << "2. Push Front." << endl;
    cout << "3. Push Back." << endl;
    cout << "4. Pop Front." << endl;
    cout << "5. Count." << endl;
    cout << "6. Size." << endl;
    cout << "7. Erase." << endl;
    cout << "8. Display." << endl;
    cout << "9. End Program." << endl;
    cout << "--> ";

    cin >> op;
    if(op == 9)
    break;
      else if (op == 1){ // Create List
        flag = true;
        cout << endl << "List created";
      }
      else if (op == 2) { // Push Front
        if(!flag)
          cout << endl << "Cannot insert element. List has not been created yet." << endl;
        else{
          double data;
          cout << endl << "Enter value to be pushed: ";
          cin >> data;
          list.push_front(data);
        }
      }
      else if (op == 3) { // Push Back
        if(!flag)
          cout << endl << "Cannot insert element. List has not been created yet." << endl;
        else{
          double data;
          cout << endl << "Enter value to be pushed: ";
          cin >> data;
          list.push_back(data);
        }
      }
      else if (op == 4) { // Pop front
        if(!flag)
          cout << endl << "Cannot pop element. List has not been created yet." << endl;
        else
          cout << endl <<list.pop_front() << " has been popped." << endl;
      }
      else if (op == 5) { // Count
        if(!flag)
          cout << endl << "Cannot count elements. List has not been created yet." << endl;
        else {
          double num;
          cout << endl << "Insert element to be counted: ";
          cin >> num;
          cout << endl << "There are " << list.count(num) << " elements of " << num << "." << endl;
        }
      }
      else if (op == 6) { // Size
        if(!flag)
          cout << endl << "Cannot display size. List has not been created yet." << endl;
        else
          cout << endl << "This list is " << list.size() << " elements long." << endl;
      }
      else if (op == 7) { // Erase
        if(!flag)
          cout << endl << "No elements to erase. List has not been created yet." << endl;
        else {
          double data;
          cout << endl << "Enter data of elements to erase: ";
          cin >> data;
          list.erase(data);
        }
      }
      else if (selection == 8) { // Display
        if(!flag)
          cout << endl << "Data cannot be displayed. List has not been created yet." << endl;
        else{
          cout << endl;
          list.Display();
        }
      }
    }
  }


  cout << endl << endl;

}
  cin.get();

  return 0;
}

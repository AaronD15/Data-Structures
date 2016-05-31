#include "DoublyLinkedList.h"

int main(){

  cout  << "This is DoublyLinkedList" << endl;

  DoublyLinkedList<double> list;
  int selection, num;
  bool flag = false;
  while(true){
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

    cin >> selection;
    if(selection == 9)
      break;
      else if (selection == 1){ // Create List
        flag = true;
        cout << endl << "List created";
      }
      else if (selection == 2) { // Push Front
        if(!flag)
          cout << endl << "Cannot insert element. List has not been created yet." << endl;
        else{
          double data;
          cout << endl << "Enter value to be pushed: ";
          cin >> data;
          list.push_front(data);
        }
      }
      else if (selection == 3) { // Push Back
        if(!flag)
          cout << endl << "Cannot insert element. List has not been created yet." << endl;
        else{
          double data;
          cout << endl << "Enter value to be pushed: ";
          cin >> data;
          list.push_back(data);
        }
      }
      else if (selection == 4) { // Pop front
        if(!flag)
          cout << endl << "Cannot pop element. List has not been created yet." << endl;
        else
          cout << endl <<list.pop_front() << " has been popped." << endl;
      }
      else if (selection == 5) { // Count
        if(!flag)
          cout << endl << "Cannot count elements. List has not been created yet." << endl;
        else {
          double num;
          cout << endl << "Insert element to be counted: ";
          cin >> num;
          cout << endl << "There are " << list.count(num) << " elements of " << num << "." << endl;
        }
      }
      else if (selection == 6) { // Size
        if(!flag)
          cout << endl << "Cannot display size. List has not been created yet." << endl;
        else
          cout << endl << "This list is " << list.size() << " elements long." << endl;
      }
      else if (selection == 7) { // Erase
        if(!flag)
          cout << endl << "No elements to erase. List has not been created yet." << endl;
        else {
          double data;
          cout << endl << "Enter data of elements to erase: ";
          cin >> data;
          list.erase(data);
        }
      }
      else if (selection == 8) {
        if(!flag)
          cout << endl << "Data cannot be displayed. List has not been created yet." << endl;
        else{
          cout << endl;
          list.Display();
        }
      }


  cout << endl << endl;
}
  cin.get();

  return 0;
}

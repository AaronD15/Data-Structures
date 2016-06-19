#include "DynStack.h"
#include "HashTable.h"
#include <sstream>

template <typename T>
string to_string(T value){
      //create an output string stream
      std::ostringstream os;

      //throw the value into the string stream
      os << value;

      //convert the string stream into a string and return
      return os.str();
  }


int main() {

  HashTable<int,string> table;
  DynStack<string> ds;
  bool run1 = true;
  int selection;

  while(run1){

  cout << endl;
  cout << "******Menu Program******" << endl;
  cout << "Please select an option." << endl;
  cout << "0. Exit" << endl;
  cout << "1. HashTable" << endl;
  cout << "2. DynStack" << endl;
  cout << "3. DynQueue" << endl;
  cout << "--> ";
  cin >> selection;
  cin.ignore();
  bool run2 = true;
  switch(selection){
  case 0:
  run1 = false;
  break;
  case 1:
    while(run2){     // HashTable START
      cout << endl;
      cout << "******Menu Program******" << endl;
      cout << "Please select an option." << endl;
      cout << "0. Return to Main Menu" << endl;
      cout << "1. getIndex" << endl;
      cout << "2. isEmpty(array)" << endl;
      cout << "3. isEmpty(linkedlist)" << endl;
      cout << "4. Insert" << endl;
      cout << "5. delValue" << endl;
      cout << "6. getValue" << endl;
      cout << "7. printTable" << endl;
      cout << "--> ";
      cin >> selection;
      cin.ignore();
      int key;
      string data;

      switch(selection){
        case 0:
          run2 = false;
        break;
        case 1:
          cout << endl << "Insert key: ";
          cin >> key;
          cin.ignore();
          cout << endl << "Index: " << table.getIndex(key) << endl;
        break;
        case 2:
          cout << endl << (table.isEmpty() ? "Table is empty.":"Table is not empty.") << endl;
        break;
        case 3:
          cout << endl << "Insert key: ";
          cin >> key;
          cin.ignore();
          cout << endl << (table.isEmpty(key) ? "Table is empty.":"Table is not empty.") << endl;
        break;
        case 4:   // Insert
          cout << endl << "Insert key: ";
          cin >> key;
          cin.ignore();
          cout << endl << "Insert data: ";
          getline(cin,data);
          table.insert(key,data);
        break;
        case 5:   // Delete Value
          cout << endl << "Insert key: ";
          cin >> key;
          cin.ignore();
          cout << endl << "Insert data: ";
          getline(cin,data);
          table.delValue(key,data);
        break;
        case 6:   // Get Value
          cout << endl << "Insert key: ";
          cin >> key;
          cin.ignore();
          table.getValue(key);
        break;
        case 7:   // Print Table
          cout << endl;
          table.printTable();
        break;
        default:
          cout << endl << "Invalid input." << endl;
      }

    }
  break;    // HashTable END

  case 2:   // DynStack START
    while(run2){
      int selection;
      cout << endl;
      cout << "******Menu Program******" << endl;
      cout << "Please select an option." << endl;
      cout << "0. Return to Main Menu" << endl;
      cout << "1. Top" << endl;
      cout << "2. Size" << endl;
      cout << "3. Empty" << endl;
      cout << "4. Capacity" << endl;
      cout << "5. Display" << endl;
      cout << "6. Push" << endl;
      cout << "7. Pop" << endl;
      cout << "8. Erase" << endl;
      cout << "9. Clear" << endl;
      cout << "--> ";
      cin >> selection;
	    cin.ignore();
      string data;

      switch(selection){
        case 0: // Return to Main Menu
          run2 = false;
        break;
        case 1: // Top
          try{cout << endl << "Top: " << ds.top() << endl;}
          catch(const underflow_error &e)
            {cout << endl << e.what() << endl;}
        break;
        case 2: // Size
          cout << endl << "Size: " << ds.size() << endl;
        break;
        case 3: // Empty
          cout << endl << (ds.empty() ? "Stack is empty.":"Stack is not empty.") << endl;
        break;
        case 4: // Capacity
          cout << endl << "Capacity: " << ds.capacity() << endl;
        break;
        case 5: // Display
          cout << endl;
          ds.display();
        break;
        case 6: // Push
          cout << endl << "Data: ";
          getline(cin, data);
          ds.push(data);
          cout << endl << data << " has been pushed." << endl;
        break;
        case 7: // Pop
          try{cout << endl << ds.pop() << " has been popped." << endl;}
          catch(const underflow_error &e)
             {cout << endl << e.what() << endl;}
        break;
        case 8: // Erase
          if(ds.empty()){
            cout << endl << "Stack is empty." << endl;
          }
          else{
            cout << endl << "Data: ";
            getline(cin, data);
            cout << endl << ds.erase(data) << " elements erased." << endl;
          }
        break;
        case 9: // Clear
          cout << endl << "Clearing..." << endl;
          ds.clear();
          cout << "List is empty." << endl;
        break;
        default:
          cout << endl << "Invalid input." << endl;
      }
    }
  break; // DynStack END

  case 3:
  // DynQueue HERE
  break;
  default:
    cout << endl << "Invalid input." << endl;

}
}
  return 0;
}

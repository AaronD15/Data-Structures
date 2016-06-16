#include "DynStack.h"

int main() {

  DynStack<string> ds;
  bool run = true;
  while(run){
    while(run){
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
          run = false;
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
}
  return 0;
}

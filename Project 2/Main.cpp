#include "DynStack.h"
#include "HashTable.h"
#include "DynQueue.h"
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

  HashTable<int,string> *table = NULL;
  DynStack<string> *ds = NULL;
  DynQueue<string> *dq = NULL;
  bool run1 = true;
  bool e1 = false, e2 = false, e3 = false;
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
      cout << "1. Create HashTable" << endl;
      cout << "2. getIndex" << endl;
      cout << "3. isEmpty(array)" << endl;
      cout << "4. isEmpty(linkedlist)" << endl;
      cout << "5. Insert" << endl;
      cout << "6. delValue" << endl;
      cout << "7. getValue" << endl;
      cout << "8. printTable" << endl;
      cout << "--> ";
      cin >> selection;
      cin.ignore();
      int key;
      string data;
      if(!e1)
        switch(selection){
          case 0:
            run2 = false;
          break;
          case 1:
            table = new HashTable<int,string>;
            e1 = true;
          break;
          default:
            cout << endl << "Hash Table hasn't been created yet." << endl;
        }
      else
        switch(selection){
          case 0:
            run2 = false;
          break;
          case 1:
          if(e1)
            delete table;

          table = new HashTable<int,string>;
          e1 = true;
          break;
          case 2:
            cout << endl << "Insert key: ";
            cin >> key;
            cin.ignore();
            cout << endl << "Index: " << table->getIndex(key) << endl;
          break;
          case 3:
            cout << endl << (table->isEmpty() ? "Table is empty.":"Table is not empty.") << endl;
          break;
          case 4:
            cout << endl << "Insert key: ";
            cin >> key;
            cin.ignore();
            cout << endl << (table->isEmpty(key) ? "Table is empty.":"Table is not empty.") << endl;
          break;
          case 5:   // Insert
            cout << endl << "Insert key: ";
            cin >> key;
            cin.ignore();
            cout << endl << "Insert data: ";
            getline(cin,data);
            table->insert(key,data);
          break;
          case 6:   // Delete Value
            cout << endl << "Insert key: ";
            cin >> key;
            cin.ignore();
            cout << endl << "Insert data: ";
            getline(cin,data);
            table->delValue(key,data);
          break;
          case 7:   // Get Value
            cout << endl << "Insert key: ";
            cin >> key;
            cin.ignore();
            table->getValue(key);
          break;
          case 8:   // Print Table
            cout << endl;
            table->printTable();
          break;
          default:
            cout << endl << "Invalid input." << endl;
        }

    }
  break;    // HashTable END

  case 2:   // DynStack START
    while(run2){
      cout << endl;
      cout << "******Menu Program******" << endl;
      cout << "Please select an option." << endl;
      cout << "0. Return to Main Menu" << endl;
      cout << "1. Create Dynamic Stack" << endl;
      cout << "2. Top" << endl;
      cout << "3. Size" << endl;
      cout << "4. Empty" << endl;
      cout << "5. Capacity" << endl;
      cout << "6. Display" << endl;
      cout << "7. Push" << endl;
      cout << "8. Pop" << endl;
      cout << "9. Erase" << endl;
      cout << "10. Clear" << endl;
      cout << "--> ";
      cin >> selection;
	    cin.ignore();
      string data;

      if(!e2){
        switch(selection){
          case 0:
            run2 = false;
          break;
          case 1:
            ds = new DynStack<string>;
            e2 = true;
          break;
          default:
            cout << endl << "Stack hasn't been created yet." << endl;
        }
      }
      else
        switch(selection){
          case 0: // Return to Main Menu
            run2 = false;
          break;
          case 1:
            if(e2)
              delete ds;

            ds = new DynStack<string>;
            e2 = true;
          break;
          case 2: // Top
            try{cout << endl << "Top: " << ds->top() << endl;}
            catch(const underflow_error &e)
              {cout << endl << e.what() << endl;}
          break;
          case 3: // Size
            cout << endl << "Size: " << ds->size() << endl;
          break;
          case 4: // Empty
            cout << endl << (ds->empty() ? "Stack is empty.":"Stack is not empty.") << endl;
          break;
          case 5: // Capacity
            cout << endl << "Capacity: " << ds->capacity() << endl;
          break;
          case 6: // Display
            cout << endl;
            ds->display();
          break;
          case 7: // Push
            cout << endl << "Data: ";
            getline(cin, data);
            ds->push(data);
            cout << endl << data << " has been pushed." << endl;
          break;
          case 8: // Pop
            try{cout << endl << ds->pop() << " has been popped." << endl;}
            catch(const underflow_error &e)
               {cout << endl << e.what() << endl;}
          break;
          case 9: // Erase
            if(ds->empty()){
              cout << endl << "Stack is empty." << endl;
            }
            else{
              cout << endl << "Data: ";
              getline(cin, data);
              cout << endl << ds->erase(data) << " elements erased." << endl;
            }
          break;
          case 10: // Clear
            cout << endl << "Clearing..." << endl;
            ds->clear();
            cout << "List is empty." << endl;
          break;
          default:
            cout << endl << "Invalid input." << endl;
        }
    }
  break; // DynStack END

  case 3:   // DynQueue START
  while(run2){
    cout << endl;
    cout << "******Menu Program******" << endl;
    cout << "Please select an option." << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "1. Create Dynamic Queue" << endl;
    cout << "2. Front" << endl;
    cout << "3. Back" << endl;
    cout << "4. Size" << endl;
    cout << "5. Empty" << endl;
    cout << "6. Capacity" << endl;
    cout << "7. Display" << endl;
    cout << "8. Enqueue" << endl;
    cout << "9. Dequeue" << endl;
    cout << "10. Clear" << endl;
    cout << "11. Erase" << endl;
    cout << "--> ";
    cin >> selection;
    cin.ignore();
    string data;

    if(!e3){
      switch(selection){
        case 0:
          run2 = false;
        break;
        case 1:
          dq = new DynQueue<string>;
          e3 = true;
        break;
        default:
          cout << endl << "Queue has not been created yet." << endl;
      }
    }
    else
      switch(selection){
        case 0:   // Return to Main Menu
          run2 = false;
        break;
        case 1:
          if(e3)
            delete dq;

          dq = new DynQueue<string>;
          e3 = true;
        break;
        case 2:   // Front
          try{ cout << endl << "Front: " << dq->front() << endl;}
          catch(const underflow_error &e)
            { cout << endl << e.what() << endl;}
        break;
        case 3:   // Back
          try{ cout << endl << "Back: " << dq->back() << endl;}
          catch(const underflow_error &e)
            { cout << endl << e.what() << endl;}
        break;
        case 4:   // Size
          cout << endl << "Size: " << dq->size() << endl;
        break;
        case 5:   // Empty
          cout << endl << (ds->empty() ? "Queue is empty.":"Queue is not empty") << endl;
        break;
        case 6:   // Capacity
          cout << endl << "Capacity: " << dq->capacity() << endl;
        break;
        case 7:   // Display
          cout << endl;
          dq->display();
        break;
        case 8:   // Enqueue
          cout << endl << "Insert data: ";
          getline(cin,data);
          dq->enqueue(data);
        break;
        case 9:   // Dequeue
          try{ cout << endl << dq->dequeue() << " has been dequeued." << endl;}
          catch(const underflow_error &e)
            { cout << endl << e.what() << endl; }
        break;
        case 10:   // Clear
          cout << endl;
          dq->clear();
        case 11:  // Erase
          cout << endl << "Insert data: ";
          getline(cin,data);
          dq->erase(data);
        break;
        default:
          cout << endl << "Invalid input." << endl;
      }
  }
  break;  // DynQueue END
  default:
    cout << endl << "Invalid input." << endl;

}
}
  return 0;
}

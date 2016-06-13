#include <iostream>
#include <stdexcept>

using namespace std;

template <class Type>
class DynStack {
private:
  Type *array;
  int count;
  int initialSize;
  int arraySize;
public:
  DynStack(int n = 13):initialSize(n),arraySize(initialSize),count(0){
    array = new Type[arraySize];
    /*cout << "Initial Size: " << initialSize << endl;
    cout << "Array Size: " << arraySize << endl;
    cout << "Count: " << count << endl;*/
  }

  ~DynStack() {
    delete[] array;
  }

  // Accessors
  Type top() const {
    if(empty())
      throw underflow_error("Stack is empty.");

    return array[count-1];                              // Return top data
  }
  int size() const { return count; }                          // Return size of stack
  bool empty() const { return count == 0; }             // If array is empty, return true
  int capacity() const { return arraySize; }                  // Return arraySize which represents the capacity
  void display() const {
    if(empty())
      cout << "Stack is empty." << endl;
    else
      for(int i = count - 1; i >= 0; i--)
        cout << array[i] << endl;
  }

  // Mutators
  void push(Type const & data) {
    if(count == arraySize)
    {
      cout << endl << "Doubling..." << endl;
      arraySize *= 2;
      Type *temp = new Type[arraySize];
      copy(array, array+count, temp);
      delete[] array;
      array = temp;
    }  // Double the array size

    array[count] = data;
    count++;
  }

  Type pop() {
    if(empty())
      throw underflow_error("Stack is empty.");

    Type data = array[count-1];
    array[--count] = "";
    if(count == arraySize/4 && arraySize > initialSize)
    {
      cout << endl << "Halfing..." << endl;
      arraySize /= 2;
      Type *temp = new Type[arraySize];
      copy(array, array+count, temp);
      delete[] array;
      array = temp;
    }  // Half the array size

    return data;
  }

  void clear() {
    delete[] array;
    count = 0;
    arraySize = initialSize;
    array = new Type[arraySize];
  }

  int erase(Type const & data) {
    // Erases elements that contain the data of the argument
    Type *temp = new Type[arraySize];
    int i = 0;
    int j = 0;
    int erased = 0;
    Type popped;

    while(!empty()) {
      popped = pop();
      if(popped != data) {
        temp[i++] = popped;
      }
      else
        erased++;
    }

    count = i-1;

    delete[] array;
    array = new Type[arraySize];

    while(i >= 0) {
        push(temp[i--]);
    }

    return erased;
  }

};

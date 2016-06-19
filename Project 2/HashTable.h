#include "LinkedList.h"

template <class Type1, class Type2>
class HashTable{
private:
  int sz;
  LinkedList<Type2> * Arr;
  int cap;
  /* Returns index to a bucket in the hash table*/
public:
  int getIndex(const Type1 & key){
      int hash = ((int) key) % 127;
      int idx = hash % cap;
      // cout << endl <<"index->" << idx << endl;
      return idx;
  }

//public:
  HashTable():sz(0),cap(31){
    Arr = new LinkedList<Type2>[cap];
  }

  HashTable(int cap):sz(0){
    this->cap = cap;
    Arr = new LinkedList<Type2>[cap];
  }

  bool isEmpty() const{ // Checks if array has any data
    return sz == 0;
  }

  bool isEmpty(const Type1 & key){ // Checks if array has data at that point
    int idx = getIndex(key);
    return Arr[idx].isEmpty();
  }

  int getSize() const{  // Returns num of elements in Table
    return sz;
  }

  void insert(const Type1 & key, const Type2 & value){  // Insert with chaining applied
    int idx = getIndex(key);
    Arr[idx].insert(value);
    sz++;
  }

  void delValue(const Type1 & key, Type2 & data){  // DELETES VALUE IN ARRAY. APPLY CHAINING HERE AS WELL.
    int idx = getIndex(key);
    if(!isEmpty()){
      Arr[idx].del(data);
    }
    else{
      cerr << "Position is already empty." << endl;
    }
  }


  void getValue(const Type1 & key){  // gets head value of linked list in the array spot.
    int idx = getIndex(key);
    if(!isEmpty(key)){
      return Arr[idx].printList();
    }
    else{
      cerr << "Position is empty" << endl;
    }
  }

  void printTable() const{    // prints the data in the array including the lists.
    for(int i = 0; i < cap; i++)
      Arr[i].printList();
  }

};

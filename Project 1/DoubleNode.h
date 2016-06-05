//*************************************************//
//	Project 1											 							   //
//	Aaron Moton					        June 5th, 2016		 //
//	Luis Dominguez																 //
//*************************************************//

template <class T>
class DoublyLinkedList;

template <class Type>
class DoubleNode{
private:
  Type data;
  DoubleNode* prev;
  DoubleNode* next;
  friend class DoublyLinkedList<Type>;
public:
  DoubleNode():data(0),prev(0),next(0){};
  DoubleNode(Type const &data, DoubleNode* prev, DoubleNode* next){
    this->data = data;
    this->prev = prev;
    this->next = next;
  }

  Type getData() const { return data; };
  DoubleNode* getPrev() const { return prev; };
  DoubleNode* getNext() const { return next; };

  ~DoubleNode(){};
};

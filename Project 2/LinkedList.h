#include "Node.h"
#include<iostream>
#include<cassert>


using namespace std;

template<class Type>
class LinkedList{
private:
    Node<Type> * head;
    int sz;

public:
    LinkedList():head(NULL), sz(0){
    }
    bool isEmpty() const{
        return head == NULL;
    }

    void insert(const Type & data){
        Node<Type> *tmp_node = new Node<Type>(data);
        Node<Type> *ptr = head;
        if (ptr == NULL){
            head = tmp_node;
            sz++;
        }
        else{
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = tmp_node;
            sz++;
        }
        printList();
    }

    void insertBefore(const Type & data, int pos){
        if(pos<=1){
            Node<Type> *newNode = new Node<Type>(data,head);
            head = newNode;
            sz++;
            printList();
        }
        else if(pos > sz){
            insert(data);
        }
        else{
            int p =1;
            Node<Type> *newNode = new Node<Type>(data);
            Node<Type> *ptr = head;
            while(p!=pos -1){
                ptr = ptr->next;
                p++;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
            printList();
        }
    }

    void del(const Type & data){
        Node<Type> *ptr = head;
        Node<Type> *prev = head;
        while(ptr!=NULL){
            if(ptr->data==data){
                if(ptr==head) head = ptr->next;
                else{
                    prev->next=ptr->next;
                    cout << ptr->ID << endl;
                    ptr = prev;
                }
            }
            prev = ptr;
            ptr = ptr->next;

        }
        printList();
    }

    void printList() const{
        Node<Type> *ptr = head;
        while(ptr !=NULL){
            cout << "Node[" << ptr->ID <<"]=" << ptr->data << "-->";
            ptr = ptr->next;
        }
        cout << "null" << endl;
    }

    void clear(){
        Node<Type> *ptr = head;
        Node<Type> * prev = head;
        while(ptr!=NULL){
            ptr = ptr->next;
            delete prev;
            prev = ptr;
        }
        head = NULL;
    }

   Type getHeadValue(){
        return head->data;
    }
};

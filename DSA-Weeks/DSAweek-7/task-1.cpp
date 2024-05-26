#include <iostream>
using namespace std;

class Node {
 public:
  int val;
  Node* next;

  Node(int value){
    val = value;
    next = nullptr;
  } 
};

class MyLinkedList {
 public:
   Node* head;
   int size;

  MyLinkedList(){
   head = nullptr;
   size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }

    return current->val;
  }

  void addAtHead(int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
    size++;
  }

  void addAtTail(int val) {
    Node* new_node = new Node(val);
    if (head == nullptr) {
      head = new_node;
    } else {
      Node* current = head;
      while (current->next != nullptr) {
        current = current->next;
      }

      current->next = new_node;
    }

    size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
      return;
    }

    if (index == 0) {
      addAtHead(val);
    } else if (index == size) {
      addAtTail(val);
    } else {
      Node* new_node = new Node(val);
      Node* current = head;
      for (int i = 0; i < index - 1; i++) {
        current = current->next;
      }

      new_node->next = current->next;
      current->next = new_node;
      size++;
    }
  }

  void display(){
    for (int i = 0; i < size; i++) {
        cout << head->val << " ";
        head = head->next;
      }
      cout << endl;
  }

};


main(){
    MyLinkedList linked_list;

    linked_list.addAtHead(1);
    linked_list.addAtTail(2);
    linked_list.addAtIndex(1, 3);

    // int val = linked_list.get(1);
    // cout << val << endl; 
    linked_list.addAtIndex(3, 4);
    linked_list.addAtHead(1);
    // linked_list.display();

    int val = linked_list.get(3); 
    cout << val << endl;

}
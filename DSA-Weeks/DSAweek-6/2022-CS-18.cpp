#include <iostream>
using namespace std;

  // { --------------------- TASK-1 --------------------- }

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  bool isEmpty() {
    return head == NULL;
  }

  void insertAtHead(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
      tail = head;
    }
  }

  void insertAtTail(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void insertBefore(int data, int key) {
    Node *newNode = new Node(data);
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      cout << "Key not found" << endl;
      return;
    }

    if (head == temp) {
      head = newNode;
      newNode->next = temp;
    } else {
      prev->next = newNode;
      newNode->next = temp;
    }
  }

  void insertAfter(int data, int key) {
    Node *newNode = new Node(data);
    Node *temp = head;
    while (temp != NULL && temp->data != key) {
      temp = temp->next;
    }

    if (temp == NULL) {
      cout << "Key not found" << endl;
      return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertAtMid(int data, int position) {
    Node *newNode = new Node(data);
    Node *temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void deleteNode(int data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != data) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    if (temp == head) {
      head = head->next;
    } else if (temp == tail) {
      tail = prev;
      tail->next = NULL;
    } else {
      prev->next = temp->next;
    }

    delete temp;
  }

  Node* searchNode(int data) {
    Node* curr = head;

    while (curr != nullptr) {
      if (curr->data == data) {
        return curr;
      }

      curr = curr->next;
    }

    return nullptr;
  }

  int getFront() {
    if (head == NULL) {
      return -1;
    } else {
      return head->data;
    }
  }

  int getTail() {
    if (tail == NULL) {
      return -1;
    } else {
      return tail->data;
    }
  }

  void removeFront() {
    if (head == NULL) {
      return;
    }

    Node *temp = head;
    head = head->next;
    if (head == NULL) {
      tail = NULL;
    }

    delete temp;
  }

  void removeTail() {
    if (tail == NULL) {
      return;
    }

    Node *temp = tail;
    if (head == tail) {
      head = NULL;
      tail = NULL;
    } else {
      Node *prev = head;
      while (prev->next != tail) {
        prev = prev->next;
      }

      tail = prev;
      tail->next = NULL;
    }

    delete temp;
  }

  void removeMiddle(int position) {
    Node *temp = head;
    Node *prev = NULL;
    for (int i = 1; i < position; i++) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    prev->next = temp->next;
    delete temp;
  }

  void printLinkedList() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  // { --------------------- TASK-3 --------------------- }

  void printListReverse(Node *head) {
    if (head == NULL) {
      return;
    }

    printListReverse(head->next);
    cout << head->data << " ";
  }

  Node *findMiddleNode() {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    Node *first = head;
    Node *last = head;

    while (last != NULL && last->next != NULL) {
      first = first->next;
      last = last->next->next;
    }

    return first;
  }

  bool isCircular() {
    Node *first = head;
    Node *last = head;

    while (last != NULL && last->next != NULL) {
      first = first->next;
      last = last->next->next;

      if (first == last) {
        return true;
      }
    }

    return false;
  }

  Node *reverseList() {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    head = prev;

    return head;
  }
};

  // { --------------------- TASK-2 --------------------- }

class Stack {
public:
  LinkedList list;

  void push(int data) {
    list.insertAtHead(data);
  }

  int pop() {
    if (list.isEmpty()) {
      return -1;
    }

    int data = list.head->data;
    list.head = list.head->next;

    return data;
  }

  int peek() {
    if (list.isEmpty()) {
      return -1;
    }

    return list.head->data;
  }

  bool isEmpty() {
    return list.isEmpty();
  }
};

class Queue {
public:
  LinkedList list;

  void enqueue(int data) {
    list.insertAtTail(data);
  }

  int dequeue() {
    if (list.isEmpty()) {
      return -1;
    }

    int data = list.head->data;
    list.head = list.head->next;

    return data;
  }

  int peek() {
    if (list.isEmpty()) {
      return -1;
    }

    return list.head->data;
  }

  bool isEmpty() {
    return list.isEmpty();
  }
};

int main() {
  LinkedList list;
  list.insertAtHead(10);
  list.insertAtHead(20);
  list.insertAtTail(40);
  list.insertAtTail(50);
  list.removeMiddle(3);
  list.removeMiddle(3);
  list.insertBefore(2,10);
  list.insertAfter(3,20);
  list.printLinkedList();
  Node* val = list.searchNode(100);

  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << stack.isEmpty()<< endl;
  stack.pop();
  stack.pop();
  stack.pop();
  cout << stack.isEmpty() << endl;

  Queue queue;
  queue.enqueue(4);
  queue.enqueue(5);
  queue.enqueue(6);
  cout << queue.isEmpty()<< endl;
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  cout << queue.isEmpty()<< endl;

  cout << "Printing the linked list in linked list order: ";
  list.printLinkedList();

  cout << "Printing the linked list in reverse linked list order: ";
  list.printListReverse(list.head);
  cout << endl;

  cout << "The middle element of the linked list is: " << list.findMiddleNode()->data
       << endl;

  bool isCircular = list.isCircular();
  cout << "Is the linked list circular: " << (isCircular ? "Yes" : "No") << endl;

  cout << "Reversing the linked list: ";
  list.head = list.reverseList();
  list.printLinkedList();
  return 0;
}

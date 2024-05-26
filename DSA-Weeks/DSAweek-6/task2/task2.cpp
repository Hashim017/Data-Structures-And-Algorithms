#include <iostream>

using namespace std;

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

  void insertBefore(int data, int target) {
    Node *newNode = new Node(data);

    if (head == NULL) {
      return;
    }

    if (head->data == target) {
      insertAtHead(data);
      return;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != target) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    newNode->next = temp;
    prev->next = newNode;
  }

  void insertAfter(int data, int target) {
    Node *newNode = new Node(data);

    if (head == NULL) {
      return;
    }

    if (tail->data == target) {
      insertAtTail(data);
      return;
    }

    Node *temp = head;
    while (temp != NULL && temp->data != target) {
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  void printLinkedList() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

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
  Stack stack;
  Queue queue;

  stack.push(10);
  stack.push(20);
  stack.push(30);
  cout<<stack.isEmpty();

  queue.enqueue(10);
  queue.enqueue(20);
  queue.enqueue(30);
  cout<<queue.isEmpty();

  cout << "Stack: ";
  while (!stack.isEmpty()) {
    cout << stack.pop() << " ";
  }
  cout << endl;
  cout<<stack.isEmpty();
  while (!queue.isEmpty()) {
    cout << queue.dequeue() << " ";
  }
  cout<<queue.isEmpty();
}
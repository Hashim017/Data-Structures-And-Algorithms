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

  void printList() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

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

int main() {
  LinkedList list;

  list.insertAtHead(10);
  list.insertAtHead(20);
  list.insertAtHead(30);
  list.insertAtHead(40);
  list.insertAtHead(50);

  cout << "Printing the linked list in linked list order: ";
  list.printList();

  cout << "Printing the linked list in reverse linked list order: ";
  list.printListReverse(list.head);
  cout << endl;

  cout << "The middle element of the linked list is: " << list.findMiddleNode()->data
       << endl;

  bool isCircular = list.isCircular();
  cout << "Is the linked list circular: " << (isCircular ? "Yes" : "No") << endl;

  cout << "Reversing the linked list: ";
  list.head = list.reverseList();
  list.printList();

  return 0;
}

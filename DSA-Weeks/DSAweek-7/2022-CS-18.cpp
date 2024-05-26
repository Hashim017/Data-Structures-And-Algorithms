#include <iostream>
using namespace std;

// --------------------------- PART-A --------------------------- //

class Node {
 public:
  int val;
  Node* prev;
  Node* next;

  Node(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
 public:
  Node* head;
  Node* tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr; 
  }

  bool empty() {
    return head == nullptr;
  }

  void insertAt(GeneralIterator iterator, int data) {
    Node* new_node = new Node(data);

    if (iterator.current == head) {
      insertAtFront(data);
    } else if (iterator.current == tail) {
      insertAtTail(data);
    } else {
      new_node->next = iterator.current;
      new_node->prev = iterator.current->prev;
      iterator.current->prev = new_node;
      new_node->prev->next = new_node;
    }
  }

  void insertAtFront(int data) {
    Node* new_node = new Node(data);

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    }
  }

  void insertAtTail(int data) {
    Node* new_node = new Node(data);

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;
    }
  }

  void removeAt(GeneralIterator iterator) {
    if (iterator.current == head) {
      head = head->next;
      if (head != nullptr) {
        head->prev = nullptr;
      } else {
        tail = nullptr;
      }
    } else if (iterator.current == tail) {
      tail = tail->prev;
      if (tail != nullptr) {
        tail->next = nullptr;
      } else {
        head = nullptr;
      }
    } else {
      iterator.current->prev->next = iterator.current->next;
      iterator.current->next->prev = iterator.current->prev;
    }

    delete iterator.current;
  }

  void splice(GeneralIterator iterator, DoublyLinkedList& other) {
    if (other.head == nullptr) {
      return;
    }

    if (iterator.current == head) {
      other.tail->next = head;
      head->prev = other.tail;
      head = other.head;
    } else if (iterator.current == tail) {
      other.head->prev = tail;
      tail->next = other.head;
      tail = other.tail;
    } else {
      other.tail->next = iterator.current;
      other.head->prev = iterator.current->prev;
      iterator.current->prev->next = other.head;
      iterator.current->prev = other.tail;
    }

    other.head = nullptr;
    other.tail = nullptr;
  }

  class ForwardIterator {
   public:
    Node* current;

    ForwardIterator(Node* head) {
        current = head;
    }

    ForwardIterator& operator++() {
      current = current->next;
      return *this;
    }

    bool operator==(const ForwardIterator& other) const {
      return current == other.current;
    }

    bool operator!=(const ForwardIterator& other) const {
      return current != other.current;
    }

    int& operator*() const {
      return current->val;
    }
  };

  class ReverseIterator {
   public:
    Node* current;

    ReverseIterator(Node* tail) {
        current = head;
    }
    ReverseIterator& operator++() {
      current = current->prev;
      return *this;
    }

    bool operator==(const ReverseIterator& other) const {
      return current == other.current;
    }

    bool operator!=(const ReverseIterator& other) const {
      return current != other.current;
    }

    int& operator*() const {
      return current->val;
    }
  };

  class GeneralIterator : public ForwardIterator, public ReverseIterator {
   public:
    GeneralIterator(Node* node) : ForwardIterator(node), ReverseIterator(node) {}
  };

  ForwardIterator fbegin() { return ForwardIterator(head); }
  ForwardIterator fend() { return ForwardIterator(nullptr); }

  ReverseIterator rbegin() { return ReverseIterator(tail); }
  ReverseIterator rend() { return ReverseIterator(nullptr); }

  GeneralIterator begin() { return GeneralIterator(head); }
  GeneralIterator end() { return GeneralIterator(nullptr); }
};

// --------------------------- PART-B --------------------------- //

// --------------------------- TASK-1 --------------------------- //

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

// --------------------------- TASK-2 --------------------------- //

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy = head;
        
        ListNode* prev = dummy;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right-left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy;
    }

// --------------------------- TASK-3 --------------------------- //

ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; 
        
        ListNode* dummyNode = new ListNode();
        
        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;
        
        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        return dummyNode->next;
    }

// --------------------------- TASK-4 --------------------------- //

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }

// --------------------------- TASK-5 --------------------------- //

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		if(l1 == NULL)
        {
			return l2;
		}
	
		if(l2 == NULL)
        {
			return l1;
		} 
		
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
#include <iostream>
using namespace std;

template <typename T>
class Stack {
public:
    LinkedList<T> S;

    Stack() {}

    void Push(T V) {
        S.insertAtHead(V);
    }

    T Pop() {
        return S.deleteAtHead();
    }

    bool IsEmpty() {
        return S.isEmpty();
    }
};

int main() {
    Stack<int> stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout << "The top element of the stack is: " << stack.Pop() << endl; // 30
    cout << "The top element of the stack is: " << stack.Pop() << endl; // 20
    cout << "The top element of the stack is: " << stack.Pop() << endl; // 10

    if (stack.IsEmpty()) {
        cout << "The stack is empty." << endl;
    }

    return 0;
}

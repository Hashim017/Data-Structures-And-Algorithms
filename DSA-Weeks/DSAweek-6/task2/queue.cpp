#include <iostream>

using namespace std;

template <typename T>
class Queue {
public:
    LinkedList<T> S; // no other memory than this

    Queue() {}

    void Enqueue(T V) {
        S.insertAtTail(V);
    }

    T Dequeue() {
        return S.deleteAtHead();
    }

    bool IsEmpty() {
        return S.isEmpty();
    }
};

int main() {
    Queue<int> queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    cout << "The element at the front of the queue is: " << queue.Dequeue() << endl; // 10
    cout << "The element at the front of the queue is: " << queue.Dequeue() << endl; // 20
    cout << "The element at the front of the queue is: " << queue.Dequeue() << endl; // 30

    if (queue.IsEmpty()) {
        cout << "The queue is empty." << endl;
    }

    return 0;
}

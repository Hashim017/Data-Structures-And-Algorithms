#include <iostream>
using namespace std;

class Solution {
public:
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
};


main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Reverse the list from position 2 to position 4
    Node* reversed_head = reverseBetween(head, 2, 4);

    // Print the reversed list
    Node* current = reversed_head;
    while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
    }

    // Output: 1 5 4 3 2


}
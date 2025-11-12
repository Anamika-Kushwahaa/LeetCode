// 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
//CODE:-
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head){
            ListNode* nextNode = head->next;
            head->next=prev;
            prev=head;
            head=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;

        // Find middle
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        slow->next = reverse(slow->next);
        slow = slow->next;

        // Compare halves
        ListNode* start = head;
        while (slow) {
            if (start->val != slow->val)
                return false;
            start = start->next;
            slow = slow->next;
        }
        return true;
    }
    
};

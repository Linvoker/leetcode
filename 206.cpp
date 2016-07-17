/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next ==NULL) {
            return head;
        } else {
            ListNode *next_node = head->next;
            ListNode *return_val = reverseList(head->next);
            next_node->next = head;
            head->next = NULL;
            return return_val;
        }
    }
};  */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            ListNode *return_node = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return return_node;
        }
        
    }

};

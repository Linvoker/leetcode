/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head ==nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *mark = head->next;
        
        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
        
            odd = odd->next;
            even = even->next;
        }
        odd->next = mark;
        return head;
    }
};

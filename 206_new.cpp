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
    /*ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *tail = head->next;
        ListNode *newNode = reverseList(head->next);
        tail->next = head;
        head->next = nullptr;
        return newNode;
    }*/
    
    //     1->2->3->4   
    //  i  j  k
    
    //nul<-1  2->3->4
    //     i  j  k
    
    //nul<-1<-2  3->4
    //        i  j  k
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *i = nullptr;
        ListNode *j = head;
        ListNode *k = head->next;
        
        while (j) {
            j->next = i;
            
            i = j;
            j = k;
            k = k ? k->next : nullptr;
        }
        return i;
    }
};

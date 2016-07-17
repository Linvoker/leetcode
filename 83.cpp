/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //这题是说删除连续几个重复出现成员，不要紧张
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next ==nullptr) {
            return head;
        }
        
        ListNode *cur = head;
        ListNode *nex = head->next;
        
        while (nex != nullptr) {
            
            if (cur->val == nex->val) {
                cur->next = cur->next->next;
                
                cur = cur;
                nex = nex->next;
            } else {
                cur = cur->next;
                nex = nex->next;
            }
            
        }
        return head;
        
           
                
     }                    
        
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //难度很大，，，，用了三个指针
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next ==nullptr) {
            return head;
        }
        ListNode root(-1);
        root.next = head;
        
        ListNode *pre = &root;
        ListNode *cur = head;
        ListNode *nex = head->next;
        
        
        while (nex != nullptr) {
            if (cur->val != nex->val) {
                pre = cur;
                cur = nex;
                nex = nex->next;
            }
            if (nex != nullptr && cur->val == nex->val) {
                while (nex != nullptr && cur->val == nex->val) {
                
                    nex = nex->next;
                }
                pre->next = nex;
                cur = nex;
                if (nex != nullptr) {
                    nex = nex->next;
                }
            }
            
        }
        return root.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //可以用递归做一便
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } 
        if (l2 == nullptr) {
            return l1;
        } 
        
      //  ListNode x(-1);
    //    ListNode *cur = &x;
       
        ListNode *mark;
        ListNode *cur;
        
       // if (l1->val <= l2->val) {
         //   mark = l1;
        //} else {
          //  mark = l2;
      // }
        mark = ((l1->val) <= (l2->val)) ? l1 : l2; 
       
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1 == nullptr) {
            cur->next = l2;
        }
        if (l2 == nullptr) {
            cur->next = l1;
        }
        //delete cur;
        return mark;
        
    }
};

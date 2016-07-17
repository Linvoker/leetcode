/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //设置两个临时单链表，一个存放小于x的链表，一个存放大于x的链表，然后遍历head，一次存入两个链表中，最后合并两个链表。
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode less_root(-1);
        ListNode *less = &less_root;
        ListNode great_root(-1);
        ListNode *great = &great_root;
        
        
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                
                less = less->next;
            } else {
                great->next = head;
                
                great = great->next;
            }
            head = head->next;
        }
        less->next = great_root.next;
        great->next = nullptr;
        
        return less_root.next;
    }
};

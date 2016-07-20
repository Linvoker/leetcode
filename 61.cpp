/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //我也许是对的，题目并未说明k>结点数要怎么处理，我选择返回head，但实际测试却要求将k % 节点数
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL) {
            return head;
        }
        
        ListNode *root;
        root->val = -21474;
        root->next = head;
        ListNode *first = root;
        ListNode *second = root;
        
        int i = k + 1;
        while (--i) {
            if (first == NULL) {
                return head;
            }
            first = first->next;
            
        }
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        if (second == root) {
            return head;
        } else {
            head = second->next;
            root->next = head;
            first->next = second;
            second->next = NULL;
            return head;
        }
    } 
};

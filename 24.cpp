/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //第一种用迭代法，第二种用递归
class Solution {
public:
    ListNode* swap(ListNode *lhs, ListNode *rhs) {
        lhs->next = rhs->next;
        rhs->next = lhs;
        
        return rhs;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode *new_head;
        ListNode *last_head;
        
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *return_val = head->next;
        while (temp != NULL && temp->next != NULL) {
            if (head == temp) {
                new_head = swap(temp, temp->next);
            } else {
                new_head = swap(temp, temp->next);
                last_head->next->next = new_head;
            }
            last_head = new_head;
            
            
            temp = temp->next;
        }
        return return_val;
    }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        } else {
            ListNode *temp = head->next;
            head->next = swapPairs(temp->next);
            temp->next = head;
            return temp;
        }
    }
};

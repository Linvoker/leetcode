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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast != nullptr && fast->next != nullptr) { //先找到链表的中间位置
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newList = reverse(slow); //翻转后半部分的链表
        
        while (newList) { //判断前半部分、后半部分链表是否相等
            if (newList->val != head->val) {
                return false;
            }
            newList = newList->next;
            head = head->next;
        }
        return true;
    }
    ListNode *reverse(ListNode* root) { //可以用三指针做，真正的O(1)时间复杂度
        if (!root->next) {
            return root;
        }
        ListNode *head = reverse(root->next);
        root->next->next = root;
        root->next = nullptr;
        return head;
    }
};

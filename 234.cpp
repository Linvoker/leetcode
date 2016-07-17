/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //143. Reorder List
 //先用两个指针不同速度前进找到中间的结点，再根据奇偶个数分开讨论将后半部分链表翻转，判断前半部分与后半部分的val是否相同
class Solution {
public:
    ListNode* reverseList(ListNode* head) { //翻转链表函数
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            ListNode *return_node = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return return_node;
        }
        
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return 1;//是回文链表
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {//考虑个数为奇数偶数的情况
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == nullptr) {//链表节点个数为偶数，也有可能是回文链表[1,2,2,1]
            
            ListNode *head1 = reverseList(slow);
            
            return isSame(head, head1);//下面的ｅｌｓｅ用到了一样的，所以封装起来
        } else {       //链表节点个数为奇数，更可能是回文链表
            slow->next = reverseList(slow->next);
            ListNode *head1 = slow->next;
            
            return isSame(head, head1);
        }
    }
    bool isSame(ListNode *head, ListNode *head1) {
        while (head1 != nullptr && head->val == head1->val) {
            head = head->next;
            head1 = head1->next;
        }
        if (head1 == nullptr) {
            return 1;//是回文
        } else {
            return 0;
        }
    }

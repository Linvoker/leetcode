/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //无意中发现。。只要将n-1，n-2,n-3,n-4个元素不停翻转，就可以达到题目的要求，不过时间复杂度为Ｏ(n^3)，无法通过测试
 //网上的方法：先使用快慢指针将链表从中间分割成两段，然后后半段就地逆置．之后合并插入到前半段链表即可，时间复杂度O(n)。 
 //234. Palindrome Linked List
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next ==nullptr) {
            return head;
        }
        
        ListNode *return_val = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return return_val;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next ==nullptr) {
            return;
        }
        
        while (head != nullptr) {
            
            head->next = reverseList(head->next);
            
            head = head->next;
        }
        return;
    }
};

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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {//这么做看起来奇怪，但这可以找到中间数或中间偏左的数，原因请看７３行
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *last_half;
        ListNode *first_half = head;
        if (fast != nullptr) {//奇数个结点，slow指向中间
            last_half = reverseList(slow->next);//翻转后半部分
            
        } else { //偶数个结点，slow指向中间靠右部分
            last_half = reverseList(slow->next);//翻转后半部分
            
        }
        
        slow->next = nullptr;//将中间数的下一个设置为ｎｕｌｌ，为了下面的循环不会出现意外
        
        ListNode *temp;
        while (last_half != nullptr) {
            temp = last_half->next;
            
            last_half->next = first_half->next;
            first_half->next = last_half;
            
            last_half = temp;
            first_half = first_half->next->next;
        }
        return;
    }
};       

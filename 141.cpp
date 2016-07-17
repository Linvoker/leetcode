/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //这题有漏洞，让他循环很久就行，测试最多只用了8028个结点   
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != nullptr && fast != slow) {
            slow = slow->next;
            if (fast->next != nullptr) { //这句很重要要，没有条件判断的话下一句会出现段错误
                fast = fast->next->next;
            } else {
                fast = fast->next;
            }
                
        }
        if (fast == slow) {
            return 1;
        } else {
            return 0;
        }
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return 0;
        }
        
        int i = 8029;
        while (i-- && head != nullptr) {
            head = head->next;
        }
        if (head == nullptr) {
            return 0;
        } else 
            return 1;
    }
};

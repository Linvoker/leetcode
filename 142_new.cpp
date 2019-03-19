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
    //2(x+m(y+z)+y) = x+n(z+y)+y  ,m是慢指针的圈数，n是快指针的圈数
    //x+y+my+mz = nz+ny
    //x = (n-2m)z + (n-2m-1)y
    //x = (a+1)z + ay
        
    ListNode *detectCycle(ListNode *head) {
        auto fast = head, slow = head;
        bool mark = false;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                mark = true;
                break;
            }
        }
        if (mark) {
            while (head != slow) {
                head = head->next;
                slow = slow->next;
            }
            return head;
        } else {
            return nullptr;
        }
    }
};

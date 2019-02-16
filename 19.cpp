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
    //这方法没有19_new.cpp的头结点法好
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int i = 0;
        for ( ; temp != NULL; ++i) {
            temp = temp->next;
        }
        temp = head;

        int end = i - n + 1;
        for (i = 1; i < end; ++i) {//找到要删除的结点（别先找前驱结点）
            temp = temp->next;
        }

        if (temp == head) {
            return head->next;
        } else {
            for (i = 1, temp = head; i < end - 1; ++i)  {
                temp = temp->next;//如果原temp不是头结点，就找到原temp的的前驱
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};
//另一种办法：另新建一个结点的next指向head，就可以直接找要删除的结点的前驱了


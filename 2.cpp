/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //每次循环都要new一个新结点,不要妄想直接改变l1或者l2的值作为返回值,因为有进n位的可能甚至相加的位数比l1,l2都长.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *move1 = l1;
        ListNode *move2 = l2;
        ListNode *root = new ListNode(-1);//先设置root结点指向返回的链表的首结点
        ListNode *move3 = root;//用一个move3做辅助为新产生的结点用next连接起来
        int mark = 0;
        while (move1 || move2 || mark == 1) {
            ListNode *new_node = new ListNode(0);
            move3->next = new_node;//每产生一个node,都把上一个结点指向它
            int move1_val = move1 ? move1->val : 0;//有可能move1,move2是nullptr
            int move2_val = move2 ? move2->val : 0;
            new_node->val = ((move1_val + move2_val) + mark) % 10;
            if (((move1_val + move2_val)  + mark) >= 10) {
                mark = 1;
            } else {
                mark = 0;
            }
            
            move1 = move1 ? move1->next : move1;//这里要注意,因为有可能下一为是nullptr
            move2 = move2 ? move2->next : move2;
            move3 = move3->next;
        }
        return root->next;
    }
};  

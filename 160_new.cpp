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
    //别人的答案，不用计算链表长度差异。到达尾部之后直接切换链表遍历即可(通过这种方式到达距离焦点相同的位置)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //boundary check
    if(headA == nullptr || headB == nullptr) return nullptr;
    
    ListNode *a = headA;
    ListNode *b = headB;
    
    //if a & b have different len, then we will stop the loop after second iteration
    while( a != b){
    	//for the end of first iteration, we just reset the pointer to the head of another linkedlist
        a = a == nullptr? headB : a->next;
        b = b == nullptr? headA : b->next;    
    }
    
    return a;
    }
    //这是我的想法，要先算两个链表的长度差异
    /*ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //先找到长度差距
        auto mov = headA;
        int cntA = 0;
        while (mov) {
            cntA++;
            mov = mov->next;
        }
        mov = headB;
        int cntB = 0;
        while (mov) {
            cntB++;
            mov = mov->next;
        }
        
        //初始化到同一位置
        int preCnt;
        if (cntA > cntB) {
            preCnt = cntA - cntB;
            while (preCnt--) {
                headA = headA->next;
            }
        } else {
            preCnt = cntB - cntA;
            while (preCnt--) {
                headB = headB->next;
            }
        }
        
        //遍历找到相同的节点
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
    }*/
};

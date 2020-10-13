#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head == nullptr) {
            return head;
        }
        //先创建一个根节点指向第一个节点(可能会删除第一个节点)
        ListNode root(0);
        root.next = head;

        ListNode *after = &root, *before = &root;     
        //先找前后指针初始位置
        for (int i = 0; i <= n; i++) {
            after = after->next;
        }

        //最终位置，before指针指向需要删除节点之前的节点
        while (after) { 
            before = before->next; 
            after = after->next; 
        }

        auto tmp = before->next;
        before->next = before->next->next; 
        delete tmp;
        //释放被删除元素的内存
        
        return root.next;
    }
};


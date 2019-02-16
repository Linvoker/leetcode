#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root{0}; //需要用一个头节点处理第一个节点的问题
        root.next = head;
        if (n <= 0 || head == NULL) {
            return head;
        }
        auto front_ptr = &root;
        auto back_ptr = front_ptr;
        for (int i = 0; i < n; ++i) { //先让前后指针间隔n
            if (front_ptr == NULL) {
                return head; //如果n大于head的长度，按不处理处理
            }
            front_ptr = front_ptr->next;
        }
        while (front_ptr->next != NULL) { //遍历到链表尾
            back_ptr = back_ptr->next;
            front_ptr = front_ptr->next;
        }
        auto tmp = back_ptr->next;
        back_ptr->next = back_ptr->next->next;
        delete tmp;
        return root.next;
    }
};

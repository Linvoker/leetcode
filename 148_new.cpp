#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
#include<climits>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    /*
    ListNode* sortList(ListNode* head) {
        auto move = head;
        int size = 0;
        while (move != nullptr) {
            size++;
            move = move->next;
        }
        ListNode res(-1);
        res.next = head;
        for (int tupleNum = 1; tupleNum < size; tupleNum *= 2) { //tupleNum 两者最大尺寸 lgn
            trySort(&res, tupleNum, size);
        }
        return res.next;
    }
    //从左到右
    void trySort(ListNode *res, int tupleNum, int size) { //n
        auto move = res, before = res->next, after = res->next;
        for (int i = 0; i < size; i += (2 * tupleNum)) {
            for (int j = 0; j < tupleNum; j++) { //找到另一个merge链表
                after = after->next;
            }
            for (int j = 0; j < tupleNum * 2 && move != nullptr; j++) { //merge
                if (before->val < after->val) {
                    move->next = before;
                } else {
                    move->next = after;
                } 
                before = before->next;
                after = after->next;
                move = move->next;
            } 
        }
    }
    */

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
    // 1->null
    // s/f
    // 1->4->null
       // s  f
    // 1->4->3->null
       // s  f
    // 1->4->2->5->null
          // s     f
    // 1->4->2->5->3->null
          // s     f
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }
        ListNode *slow = head, *fast = head, *prev = head;
        while (fast && fast->next) { //找到中间节点
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;// 这个变量很重要，它将一个链表拆成两个（对半拆）

        auto left = sortList(head);
        auto right = sortList(slow);

        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode tmp(0);
        ListNode *move = &tmp;
        while (left && right) {
            if (left->val > right->val) {
                move->next = right;
                right = right->next;
            } else {
                move->next = left;
                left = left->next;
            }
            move = move->next;
        }

        if (left == nullptr) {
            move->next = right;
        } else if (right == nullptr) {
            move->next = left;
        }
        return tmp.next;
    }
};
};
int main () {
    //(new Solution)->
}

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode *it = &root;
        while (l1 || l2) {
            if (!l1) {
                it->next = l2; 
                break;
            } else if (!l2) {
                it->next = l1;
                break;
            } else {
                if (l1->val > l2->val) {
                    it->next = l2;
                    l2 = l2->next;
                } else {
                    it->next = l1;
                    l1 = l1->next;
                }
                it = it->next;
            }
        }
        return root.next;
    }
};

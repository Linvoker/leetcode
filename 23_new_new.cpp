#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeHelper(lists, 0, lists.size() - 1); 
    }
    ListNode* mergeHelper(vector<ListNode*>& lists, int i, int j) {
        if (i == j) {
            return lists[i];
        } 
        int mid = (i + j) / 2; //TODO 优化
        ListNode *left = mergeHelper(lists, i, mid);
        ListNode *right = mergeHelper(lists, mid + 1, j);
        return mergeTwoLists(left, right);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root;
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

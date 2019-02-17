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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        int size = lists.size();
        return mergeHelper(lists, 0, size - 1);
    }
    ListNode *mergeHelper(vector<ListNode*>& lists, int beg, int end) {
        if (beg == end) {
            return lists[beg];
        } else {
            ListNode *l1 = mergeHelper(lists, beg, (beg+end)/2);
            ListNode *l2 = mergeHelper(lists, (beg+end)/2+1, end);
            return mergeTwoLists(l1, l2);
        }
    }
    //下面直接抄的21题
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        
        ListNode *res = NULL;
        ListNode *cur = NULL;
        ListNode *another = NULL;
        if (l1->val <= l2->val) {
            cur = res = l1;
            another = l2;
        } else {
            cur = res = l2;
            another = l1;
        }
        
        while (cur && another) {
            ListNode *tmp = NULL;
            if (cur->next != NULL && cur->next->val < another->val) {
                cur = cur->next;
            } else {
                tmp = cur->next;
                cur = cur->next = another;
                another = tmp;
            }
        }
        return res;
    }
    
};

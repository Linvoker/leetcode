#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //21.cpp的递推公式更严谨一些
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else {
            return NULL;
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
        
        while (cur->next) {
            ListNode *tmp = NULL;
            if (cur->next->val < another->val) {
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
int main () {
    ListNode x(1);
    ListNode y(2);
    ListNode z(4);
    x.next = &y; y.next = &z;

    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    a.next = &b; b.next = &c;

    Solution w;
    ListNode * tmp = w.mergeTwoLists(&x, &a);
    while (tmp) {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

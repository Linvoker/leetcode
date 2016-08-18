/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }
    TreeNode* helper(ListNode* head, ListNode *end) {//end是要转换的链表最后一位的下一位
        if (head == end) {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != end && fast->next != end) {// 寻找中间节点
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *new_head = new TreeNode(slow->val);
        new_head->left = helper(head, slow);
        new_head->right = helper(slow->next, end);
        
        return new_head;
    }
};

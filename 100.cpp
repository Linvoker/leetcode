/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //用递归来做
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {//如果不同时等于nullptr，并且至少有一个等于nullptr
            return false;
        } else if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val) {
            return true;
        } else {
            return false;
        }
    }
};

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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        find(root, k, res);
        return res;
    }
    void find(TreeNode* root, int &k, int &res) {
        if (k <= 0 || !root) {
            return;
        }
        find(root->left, k, res);
        if (--k == 0) {
            res = root->val;
            return;
        }
        find(root->right, k, res); 
    }
};

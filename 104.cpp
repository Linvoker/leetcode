/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //深度优先算法，递归，栈，前序遍历
/*class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int lhs = maxDepth(root->left);
        int rhs = maxDepth(root->right);
        return lhs > rhs ? lhs + 1 : rhs + 1;
    }
};*/
//广度优先算法，迭代，队列，层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q_t;
        q_t.push(root);
        int count = 1;
        int depth = 0;
        
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            q_t.pop();
            if (--count == 0) {
                count = q_t.size();
                depth++;
            }
        }
        return depth;
    }
};

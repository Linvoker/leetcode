/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //preorder最简单
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int> ();
        } 
        vector<int> v_int;
        stack<TreeNode *> s_t;
        
        s_t.push(root);
        while (!s_t.empty()) {
            TreeNode *s_top = s_t.top();
            v_int.push_back(s_top->val);
            s_t.pop();
            if (s_top->right) {
                s_t.push(s_top->right);
            }
            if (s_top->left) {
                s_t.push(s_top->left);
            }
            
        }
        return v_int;
        
        
    }
};

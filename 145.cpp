/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //
 //pre-order traversal is root-left-right, and post order is left-right-root. modify the code for pre-order to make it root-right-left, and then reverse //the output so that we can get left-right-root .


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int> ();
        }
        stack<TreeNode *> s_t;
        vector<int> v_int;
       // TreeNode *move = root;
        
        s_t.push(root);
        while(!s_t.empty()) {
            TreeNode *s_top = s_t.top();
            v_int.push_back(s_top->val);
            s_t.pop();
            if (s_top->left) {
                s_t.push(s_top->left);
            }
            if (s_top->right) {
                s_t.push(s_top->right);
            }
        }
        reverse(v_int.begin(), v_int.end());
        return v_int;
    }
};

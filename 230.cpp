/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //中序遍历，出栈的次数就是k的值
/*class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       // stack<TreeNode *> s_t;
        int mark = k;
        int ret_val;
        inorderTraversal(root, mark, ret_val);
        return ret_val;
        
    }
    void inorderTraversal(TreeNode *root, int &mark, int &ret_val) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left, mark, ret_val);
        if (!(--mark)) {
            ret_val = root->val;
            return;
        }
        inorderTraversal(root->right, mark, ret_val);
        return;
    }
};*/
//迭代实现的中序遍历
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s_t;
        int ret_val;
        TreeNode *temp = root;
        s_t.push(root);
        while (k && (!s_t.empty() || temp)) {//以第一个运算符为分界计算左边和右边的bool值
            if (temp) {
                s_t.push(temp);
                temp = temp->left;
            } else {
                k--;
                ret_val = s_t.top()->val;
                temp = s_t.top()->right;
                s_t.pop();
                
            }
        }
        return ret_val;
        
    }
};

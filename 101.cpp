/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归实现
/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirrorTree(root->left, root->right);
    }
    bool isMirrorTree(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == nullptr && rhs == nullptr) {
            return true;
        } else if (lhs == nullptr || rhs == nullptr) {//如果不同时等于nullptr，并且至少有一个等于nullptr
            return false;
        } else if (isMirrorTree(lhs->left, rhs->right) && 
                 isMirrorTree(lhs->right, rhs->left) && lhs->val == rhs->val) {//lhs,rhs都不为nullptr时
            return true;
        } else {
            return false;
        }
    }
};*/
//迭代实现
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
       stack<TreeNode *> s_t;
       s_t.push(root->left);
       s_t.push(root->right);
       while (!s_t.empty()) {
           TreeNode *rhs = s_t.top();
           s_t.pop();
           TreeNode *lhs = s_t.top();
           s_t.pop();
           if (rhs == nullptr && lhs == nullptr) {
               continue;
           } else if (rhs == nullptr || lhs == nullptr) {
               return false;
           } else if (rhs->val != lhs->val) {
               return false;
           } else {
               s_t.push(lhs->left);
               s_t.push(rhs->right);
               s_t.push(lhs->right);
               s_t.push(rhs->left);
           }
       }
       return true;
    }
};

#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    //root左边所有节点小于root，root右边所有节点大于root&&root左子树是BST，右子树是BST
    bool helper(TreeNode *root, TreeNode* pmin, TreeNode* pmax) {
         
        if (root == NULL) {
            return true;
        }
        //这逻辑可以省略
        // if ((root->left != NULL && root->left->val >= root->val) || (root->right != NULL && root->right->val <= root->val)) {
            // return false;
        // }
        //这逻辑可以省略

        if (pmin != NULL && root->val <= pmin->val) {
            return false;
        }
        if (pmax != NULL && root->val >= pmax->val) {
            return false;
        }
        return helper(root->left, pmin, root) && helper(root->right, root, pmax);
    }
};

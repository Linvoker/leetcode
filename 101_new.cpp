#include<vector>
#include<iostream>
#include<stack>
//#include<unordered_set>
#include<climits>
//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

using namespace std;
//看101.cpp的迭代实现比较好
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) {
            return false; 
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left) && left->val == right->val;
    }
};

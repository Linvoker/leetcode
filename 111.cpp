/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//两种做法：一种用递归进行深度优先搜索dfs，另一种用queue队列进行广度优先搜索bfs
 
 //用递归，树的最小高度为非空左子树最小高度与非空右子树最小高度的最小值+1，
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        } 
        if (root->right == nullptr) { //右子树为空时只计算左子树的最小高度
            return minDepth(root->left) + 1;
        } else if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        } else 
        return min(minDepth(root->right), minDepth(root->left)) + 1;// if (root->right != nullptr && root->left != nullptr)
    }
};
};

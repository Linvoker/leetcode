/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归，bfs，后续遍历，从下往上。这个递归很难想明白。这题是看答案的
 //用返回值记录常规递归最大值即左孩子（包括结点在内）的最大值+右孩子（包括结点在内）的最大值+该结点的val
 //同时用一个全局变量每次迭代完毕都更新真正的最大路径，即左孩子（不一定包含该结点）的最大值和右孩子（不一定包括该结点）的最大值
 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        helper(root, maxPath);
        return maxPath;
    }
private:
    int helper(TreeNode *root, int &maxPath) {
        if (!root) {
            return 0;
        }
        int left_max = max(0, helper(root->left, maxPath));
        int right_max = max(0, helper(root->right,maxPath));
        maxPath = max(left_max + right_max + root->val, maxPath);
        return max(left_max, right_max) + root->val; 
    }
}; 

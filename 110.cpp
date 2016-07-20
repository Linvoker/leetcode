/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //用主方法分析递归算法
 
 //#include<cstdlib>  abs(int)返回两个数的绝对值
 //一个树是否高度平衡在于:左子树平衡 && 右子树平衡 && 左子树右子树高度差不大于1
 
 //常规方法是用两个递归
class Solution {
public:
    bool isBalanced(TreeNode* root) { //T(n) = 2T(n/2) + O(n); 时间复杂度为O(nlgn)
        if (root == nullptr) {
            return true;
        }
        //return isBalanced(root->left) && isBalanced(root->right) && (height(root->left) - height(root->right) <= 1) && (height(root->left) - height//(root->right) >= -1);
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }
private:
    int height(TreeNode *root) { //T(n) = 2T(n/2) + O(1); 时间复杂度为O(n)
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
};
//使用一个递归，如果树不平衡返回-1，平衡则返回树的高度
/*class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return dfsHeight(root) != -1;
    }
private:
    int dfsHeight(TreeNode *root) {//T(n) = 2T(n/2) + O(1); 时间复杂度为O(n)
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = dfsHeight(root->left);
        int rightHeight = dfsHeight(root->right);
        
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        } else if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
        
    }
};

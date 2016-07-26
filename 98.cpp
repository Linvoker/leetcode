/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //常规思路：小于左子树的最大结点并大于右边子树的最小结点，并且左子树是BST，右子树也是BST
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        TreeNode *leftMax = root->left;
        TreeNode *rightMin = root->right;
        while (leftMax && leftMax->right) {
            leftMax = leftMax->right;
        }
        while (rightMin && rightMin->left) {
            rightMin = rightMin->left;
        }
        
        
        if (rightMin && root->val >= rightMin->val || leftMax && root->val <= leftMax->val) {//
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
        /*if (!rightMin && leftMax) {
            return leftMax->val < root->val && isValidBST(root->left);
        } else if (rightMin && !leftMax) {
            return rightMin->val > root->val && isValidBST(root->right);
        } else if (rightMin && leftMax) {
            return rightMin->val > root->val && leftMax->val < root->val && isValidBST(root->right) && isValidBST(root->left);
        } else {
            return true;
        }*/
    }
};
//别人的思路：用一个helper()，并将最小值结点和最大值结点作为参数传递给这个函数
/*class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
private:
    bool helper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (!root) {
            return true;
        }
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) {//minNode存在并大于root才会返回false
            return false;
        } else {
            return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
        }
    }
};
//还有一个思路就是前序遍历用两个指针记录大小看看是否满足升序排列

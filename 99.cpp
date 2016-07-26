/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //mdzz，找到后直接更改两个结点的val就行
 //题中要求O(1)，以下三个个答案都未达到要求，使用morris traversal才能达到要求（线索二叉树）
 
 //先将中序遍历到vector里，然后再vector里找到那两个要交换的结点，再交换他们的val，60ms
/*class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> v_t;
        inorderTraversal(root, v_t);
        TreeNode *lhs;
        TreeNode *rhs;
        int count = 2;
        auto it1 = v_t.begin();
        auto it2 = v_t.begin() + 1;
        for ( ; it2 != v_t.end(); ++it1, ++it2) {
            if ((*it1)->val > (*it2)->val) {
                if (--count) {
                    lhs = *it1;
                    rhs = *it2;//如果不会出现第二次前面的数大于后面的数，则说明rhs和lhs相邻
                } else {
                    rhs = *it2;
                    break;
                }
            }
        }
        int temp = rhs->val;
        rhs->val = lhs->val;
        lhs->val = temp;
    }
private:
    void inorderTraversal(TreeNode *root, vector<TreeNode *> &v_t) {
        if (!root) {
            return;
        }
        inorderTraversal(root->left, v_t);
        v_t.push_back(root);
        inorderTraversal(root->right, v_t);
    }
    
};*/
//直接在树里中序遍历找到两个需要更改的结点，然后出来交换val，48ms
/*class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> v_t;
        TreeNode *lhs = nullptr;
        TreeNode *rhs = nullptr;
        TreeNode *pre_node = new TreeNode(INT_MIN);
        inorderTraversal(root, pre_node, lhs, rhs);
        
        
        int temp = rhs->val;
        rhs->val = lhs->val;
        lhs->val = temp;
    }
private:
    void inorderTraversal(TreeNode *root, TreeNode* &pre_node, TreeNode* &lhs, TreeNode* &rhs) {//对，指针也可以引用，即在地址上改动,否则只是地址的副本
        if (!root) {
            return;
        }
        inorderTraversal(root->left, pre_node, lhs, rhs);
        if (!rhs && pre_node->val > root->val) {
            lhs = pre_node;    
        } 
        if (pre_node->val > root->val) {
            rhs = root;
        } 
        pre_node = root;
        
        inorderTraversal(root->right, pre_node, lhs, rhs);
    }
    
};*/
//方法2的迭代实现
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> v_t;
        TreeNode *lhs = nullptr;
        TreeNode *rhs = nullptr;
        TreeNode *pre_node = new TreeNode(INT_MIN);//#include<climits>
        stack<TreeNode *> s_t;
        //s_t.push(root);
        TreeNode *move = root;
        while (!s_t.empty() || move) {
            if (move) {
                s_t.push(move);
                move = move->left;
            } else {
                TreeNode *s_top = s_t.top();
                if (!rhs && pre_node->val > s_top->val) {
                    lhs = pre_node;
                }
                if (pre_node->val > s_top->val) {
                    rhs = s_top;
                }
                pre_node = s_top;
                
                s_t.pop();
                move = s_top->right;
            }
        }
        
        
        int temp = rhs->val;
        rhs->val = lhs->val;
        lhs->val = temp;
        return ;
    }
    
};


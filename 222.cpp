/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //题目没说不能用O(N)的做法，但用了却出现time limited exceeded
/*class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        queue<TreeNode *> q_t;
        q_t.push(root);
        int count = 1;//初始化为1是因为root已入队
        int sum = 1;
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            
            q_t.pop();
            if (--count == 0) {
                count = q_t.size();
                sum += count;
            }
            
        }
        return sum;
    }
};*/
//还是错的，timelimitedexceeded
//pow(x, y)计算x^y
/*class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left) {
            return 1;
        }
        int tree_level = 0;
        TreeNode *move = root;
        while (move) {
            tree_level++;
            move = move->left;
        }
        int counter = 0;
        bool mark = true;
        inorderTraversal(root, 1, tree_level, counter, mark);
        return pow(2, tree_level - 1) - 1 + counter;
    }
private:
    void inorderTraversal(TreeNode *root, int cur_level, const int tree_level, int &counter, bool &mark) {
         if (!mark) {
             return;
         }
         if (cur_level == tree_level) {
             if (root) {
                counter++;
             } else {
                mark = false;
             }
             return;
         } else {
             inorderTraversal(root->left, cur_level + 1, tree_level, counter, mark);
            inorderTraversal(root->right, cur_level + 1, tree_level, counter, mark);
         }
         return;
     }
};*/
//利用递归dfs，如果最左边的结点的深度和最右边的结点的深度不一致，结点数等于左子树结点的个数+右边子树的个数+1；如果一致，则直接用高度计算节点数
//T(n) = T(n/2) + O(lgn) 要么是两个完美/满 二叉树（perfect binary tree），要么是一个完美二叉树，一个完全（complete）二叉树
//master theorem 的case 2:时间复杂度为O((lgn)^2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = 0;
        int right_depth = 0;
        TreeNode *left_move = root;
        TreeNode *right_move = root;
        while (left_move) {
            left_depth++;
            left_move = left_move->left;
        }
        while (right_move) {
            right_depth++;
            right_move = right_move->right;
        }
        if (left_depth == right_depth) {
            return pow(2, left_depth) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }

};


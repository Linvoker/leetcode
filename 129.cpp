/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //直观感觉使用深度优先算法dfs，递归
 //这是我的复杂办法，甚至递归得有点乱（有点像113题的回溯问题）
/*class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        string str;
        return helper(root, str);
        
    }
private:
    int helper(TreeNode *root, string &str) {
        if (!root) {
            return 0;
        }
        str.push_back(root->val + '0');
        if (!root->left && !root->right) {
            int ret = atoi(str.c_str());
            str.erase(str.end() - 1) ;//从str里删除最近push_back的元素
            return ret;
        }
        int ret_int = helper(root->left, str) + helper(root->right, str);
        str.erase(str.end() - 1) ;//从str里删除最近push_back的元素
        return ret_int;
    }
};*/
//这是大部分人的做法，这个做法比较好，递归里没有用到引用，不会使代码变得复杂
//没用string，而是直接计算结果,用cur_val参数来保存该结点之前结点若为叶子结点时的总值
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        //if (!root) {
        //    return 0;
        //}
        //if (!root->left && !root->right) {
          //  return root->val;
        //}
        return helper(root, 0);
        
    }
private:
    int helper(TreeNode *root, int cur_val) {
        if (!root) {
            return 0;
        }
        
        cur_val = root->val + cur_val * 10;
        if (!root->left && !root->right) {
            return cur_val;
        }
        
        return helper(root->left, cur_val) + helper(root->right, cur_val);
    }
};

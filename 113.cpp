/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //dfs+典型的回溯问题
 //参考112
 //每个结点依次push_back()进vector<int>，又依次pop_back,只有当出现满足条件的路径时才push_back到vector<vector<int>>里
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret_vec;
        vector<int> temp;
        findPath(root, sum, ret_vec, temp);
        return ret_vec;
    }
private:
    void findPath(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &temp) {
        if (root == nullptr) {
            return;
        } 
        
        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {//只有出现满足条件的路径时才push_back到result里
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        findPath(root->left, sum - root->val, result, temp);
        findPath(root->right, sum - root->val, result, temp);
        temp.pop_back();
    }
};

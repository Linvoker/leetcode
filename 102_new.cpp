#include<vector>
#include<iostream>
#include<queue>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int qu_size = qu.size();
            int i = 0;
            vector<int> data;
            while (i++ < qu_size) {
                auto qf = qu.front();
                data.push_back(qf->val);
                if (qf->left) {
                    qu.push(qf->left);
                }
                if (qf->right) {
                    qu.push(qf->right);
                }
                qu.pop();
            }
            res.push_back(data);
        }
        return res;
    }
    // vector<vector<int>> levelOrder(TreeNode* root) {
        // vector<vector<int>> res;
        // int level = 0;
        // travel(root, level, res);
        // return res;
    // }
    // void travel(TreeNode *root, int level, vector<vector<int>> &res) {
        // if (root == NULL) {
            // return;
        // }
        // if (res.size() < level + 1) {
            // res.resize(level + 1, vector<int>{});
        // }
        // res[level].push_back(root->val); 
        // travel(root->left, level + 1, res);
        // travel(root->right, level + 1, res);
    // }
};

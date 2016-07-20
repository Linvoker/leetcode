/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //我误解题意了，以为只是从小到大展开。然后我用dfs深度优先算法将每个结点的指针保存到vector<TreeNode ×*>
 //里，再用stl里的sort对vector排序，再将树变成上图形式
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        vector<TreeNode *> result;
        pushVector(root, result);
        if (result.size() == 1) {
            return;
        }
        sort(result.begin(), result.end(), compare);
        
        auto it1 = result.begin();
        auto it2 = result.begin() + 1;
        for (; it2 != result.end(); ++it1, ++it2) {
            (*it1)->left = nullptr;
            (*it1)->right = *it2;
        }
        (*it1)->left = nullptr;
        (*it1)->right = nullptr;
    }
private:
    void pushVector(TreeNode *root, vector<TreeNode *> &result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root);
        pushVector(root->left, result);
        pushVector(root->right, result);
        return;
    }
    static bool compare(TreeNode *lhs, TreeNode *rhs) {
        return lhs->val <  rhs->val;
    }
}; 

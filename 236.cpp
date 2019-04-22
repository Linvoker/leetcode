/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //参考113. Path Sum II，将前序遍历得到的路径放入vector里，回溯问题
 //对比两个vector在第几位开始不同

//前序遍历节点, 先找到p,q. 同时记录下从root到该几点的路径。之后比较路径,最后一个相同的节点便是LCA.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v_path_p;
        vector<TreeNode *> v_path_q;
        vector<TreeNode *> path;
        preorderTraversal(root, p, q, path, v_path_p, v_path_q);
        int i = 0;
        for (; ;i++) {
            if (v_path_p[i] != v_path_q[i]) {
                break;
            }
        }
        return v_path_q[i - 1];
    }
private:
    //path用于记录其路径
    void preorderTraversal(TreeNode *root, TreeNode* p,TreeNode* q, 
            vector<TreeNode *> &path,vector<TreeNode *> &v_path_p,vector<TreeNode *> &v_path_q) {
        if (!root) {
            return;
        }
        
        if (!v_path_p.empty() && !v_path_q.empty()) {//如果找全了
            return;
        }
        
        path.push_back(root);
        
        if (root == p) {
            v_path_p = path;
        } 
        if (root == q) {
            v_path_q = path;
        }
        
        preorderTraversal(root->left, p, q, path, v_path_p, v_path_q);
        preorderTraversal(root->right, p, q, path, v_path_p, v_path_q);
        path.pop_back();
    }
};

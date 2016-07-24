/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //前序遍历，回溯问题,见113. Path Sum II
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ret_vec;
        vector<int> ele;
        helper(root, ret_vec, ele);
        vector<string> v_str;
        string str;
        for (auto &v_v: ret_vec) {
            for (auto &v : v_v) {
                //string temp;
               // stringstream ss;
                //ss << v;
                //ss >> temp;
                //str += temp;
                str += to_string(v);
                str += "->";
            }
            str.pop_back();
            str.pop_back();//删除最后一个"->"
            v_str.push_back(str);
            str.clear();
        }
        return v_str;
        
    }
private:
    void helper(TreeNode *root, vector<vector<int>> &ret_vec, vector<int> ele) {
        if (!root) {
            return;
        }
        
        ele.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            ret_vec.push_back(ele);
            //ele.clear();
        }
        
        helper(root->left, ret_vec, ele);
        helper(root->right, ret_vec, ele);
        ele.pop_back();
        
    }
};
//更简洁的代码
/*class Solution {
public:
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;
    
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}
};

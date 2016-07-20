/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //两个思路：1.将每层暂时放入栈中，最后出栈并vectro::push_back,空间会多出O(lgn)
 //2.直接放入vecor<vector<int>>里，用stl:reserve()来处理，时间会多出O(lgn/2),但其实第一种方法也要时间重新出栈，所以时间上差不多

//8ms
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<TreeNode *> q_t;
        stack<vector<int>> s_v_int;
        q_t.push(root);
        int count = 1;
        vector<int> temp;
        vector<vector<int>> ret_vec;
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            temp.push_back(q_t.front()->val);
            q_t.pop();
            if (--count == 0) {
                count = q_t.size();
                s_v_int.push(temp);
                temp.clear();
            }
        }
        while(!s_v_int.empty()) {
            ret_vec.push_back(s_v_int.top());
            s_v_int.pop();
        }
        return ret_vec;
    }
};
//可以到4ms
/*class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<TreeNode *> q_t;
        q_t.push(root);
        int count = 1;
        vector<int> temp;
        vector<vector<int>> ret_vec;
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            temp.push_back(q_t.front()->val);
            q_t.pop();
            if (--count == 0) {
                count = q_t.size();
                ret_vec.push_back(temp);
                temp.clear();
            }
        }
        reverse(ret_vec.begin(), ret_vec.end());
        return ret_vec;
    }
};

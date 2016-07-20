/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //参考102题，按照level从左往右遍历，将偶数行翻转而已
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<TreeNode *> q_t;
        q_t.push(root);
        vector<vector<int>> ret_vec;
        vector<int> temp;
        int count = 1;
        bool mark = true; 
        
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
                if (mark == false) {//只有隔一层才翻转一次vector<int>
                    reverse(temp.begin(), temp.end());
                }
                ret_vec.push_back(temp);
                temp.clear();
                
                mark = !mark;
            }
        }
        return ret_vec;
    }
};

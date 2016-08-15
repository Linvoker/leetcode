/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //可以用一个队列来实现
 
 //用一个count来确保一个level结束后vector<vector<int>>::push_back调用一次
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();//返回空vector
        }
        
        queue<TreeNode *> q_t;
        q_t.push(root);
        vector<vector<int>> ret_vec;
        vector<int> temp;
        int count = 1;//记录当前层的元素个数,初始化为1是因为root已入队
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            temp.push_back(q_t.front()->val);
            q_t.pop();
            if (--count == 0) {//当前层已全部出队了
                ret_vec.push_back(temp);
                temp.clear();
                count = q_t.size();
            }
            
        }
        return ret_vec;
    }
};
//不用count，用两个循环，但总的循环次数是一样的。
/*class Solution {
public:
        vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int len = q.size();
        vector<int> level;
        for (int i = 0;i < len;++i) {
            TreeNode *node = q.front();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            q.pop();
        }
        ans.push_back(level);
    }
    return ans;
}
    
};



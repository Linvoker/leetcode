/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //每一层只有一个结点被看到。
 //思路1：BFS，用queue（空间复杂度为O(n)）迭代实现，根据二叉树层序遍历，将每一层最后一个结点的val保留下来即可
 //思路2：DFS，不用额外空间复杂度,递归实现，每一层必须有且只有一个结点的树被保留。
 
 //思路1
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return vector<int>();//返回空vector
        }
        vector<int> v_int;
        queue<TreeNode *> q_t;
        q_t.push(root);
        int count = 1;
        TreeNode *mostRightNode;
        while (!q_t.empty()) {
            count = q_t.size();
            while (count--) {
                TreeNode *q_front = q_t.front();
                if (q_front->left) {
                    q_t.push(q_front->left);
                }
                if (q_front->right) {
                    q_t.push(q_front->right);
                }
                mostRightNode = q_front;
                q_t.pop();
            }
            v_int.push_back(mostRightNode->val);
        }
        return v_int;
    }
};
//思路1
/*class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();//返回空vector
        }
        
        queue<TreeNode *> q_t;
        q_t.push(root);
        vector<int> v_int;
        int count = 1;//初始化为1是因为root已入队
        while (!q_t.empty()) {
            if (q_t.front()->left != nullptr) {
                q_t.push(q_t.front()->left);
            }
            if (q_t.front()->right != nullptr) {
                q_t.push(q_t.front()->right);
            }
            TreeNode *temp = q_t.front();
            q_t.pop();
            if (--count == 0) {
                v_int.push_back(temp->val);
                count = q_t.size();
            }
            
        }
        return v_int;
    }
};
 //递归不是我写的，抄来的
 class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);//下一层如果不是该结点的右孩子就是左孩子,如果都不是则return回上一层
        recursion(root->left, level+1, res);
        return;  
        }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //第一中做法：用一个栈来存放，树的结构会被破坏，不想被破坏可以使用包裹结构体，
 //可以定义另一个树结点结构包含原有的树的结构并多有两个bool成员：结点左成员已被访问，结点右成员已被访问,然后每一步循环都要new一个新的新结构结点

//第二种做法（很难想到的做法，但很基础）基本过程(思路)：
//1.迭代将move指针指向的非空结点入栈并将move指针移动到其左孩子。2.move指针为空，则出栈并将之前栈顶的右孩子入栈，move指针指向这个右孩子。3.重复1过程
//参考173BST的问题
/*class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> v_int;
        stack<TreeNode *> s_t;
        s_t.push(root);
        while (!s_t.empty()) {
            
            if (s_t.top()->left) { //树的结构被破坏
                TreeNode *temp = s_t.top()->left;
                s_t.top()->left = nullptr;
                s_t.push(temp);
            } else if (s_t.top()->right){
                v_int.push_back(s_t.top()->val);
                TreeNode *temp = s_t.top()->right;
                s_t.pop();
                s_t.push(temp);
            } else {
                v_int.push_back(s_t.top()->val);
                s_t.pop();
            }
        }
        return v_int;
    }
};*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return vector<int>();
        }
        vector<int> v_int;
        stack<TreeNode *> s_t;
        TreeNode *move = root;
        
        
        while (!s_t.empty() || move) {//这个move很重要
            if (move) {
                s_t.push(move);
                move = move->left;
            } else {
                v_int.push_back(s_t.top()->val);
                move = s_t.top()->right;
                s_t.pop();
            }
            
        } 
        return v_int;
    }
};

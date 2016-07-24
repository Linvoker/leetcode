/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //参见中序遍历94，非递归遍历
 ////根据摊还分析，next()时间复杂度也是O(1)
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushLeftNode(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s_t.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            TreeNode *s_top = s_t.top();
            s_t.pop();
            pushLeftNode(s_top->right);
            return s_top->val;
        }
        return -1;
    }
private:
    stack<TreeNode *> s_t;

    void pushLeftNode(TreeNode *root) {
       // if (!root) { //递归实现
        //    return;
       // }
       // s_t.push(root);
       // pushLeftNode(root->left);
       while (root) { //迭代实现
           s_t.push(root);
           root = root->left;
       }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //详见105题
 //不用管什么深度优先算法，直接按照后序遍历和中序遍历的特征来做
 //       _______7______
 //      /              \
  //  __10__          ___2
 //  /      \        /
  // 4       3      _8
 //           \    /
 //            1  11
 //post:4,1,3,10,11,8,2,⑦
 //in:4,10,3,1,⑦,11,8,2
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        return buildTreeRecursion(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode *buildTreeRecursion(vector<int>& inorder, vector<int>& postorder, int post_end, int in_beg, int in_end) {
        TreeNode *new_node = new TreeNode (postorder[post_end]);
        int i;
        if (in_beg > in_end) {
            return nullptr;
        }
        for (i = in_beg; i <= in_end; i++) {
            if (postorder[post_end] == inorder[i]) {
                break;
            }
        }
        
        new_node->right = buildTreeRecursion(inorder, postorder, post_end - 1, i + 1, in_end);
        new_node->left = buildTreeRecursion(inorder, postorder, post_end - (in_end - i) - 1, in_beg, i - 1);
        return new_node;
    }
};

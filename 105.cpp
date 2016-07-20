/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //       _______7______
 //      /              \
  //  __10__          ___2
 //  /      \        /
  // 4       3      _8
 //           \    /
 //            1  11
 //pre:⑦,10,4,3,1,2,8,11
 //in:4,10,3,1,⑦,11,8,2
 //不用管什么深度优先算法，直接按照前序遍历和中序遍历的特征来做
 //The first element in preorder array can divide inorder array into two parts. Then we can divide preorder array into two parts(inorder里中间结点的左边为左子树，而preorder里左子树在右子树之后，从而可以将preorder用左子树个数分成一半，得到参数pre_beg). Make this element a //node. And the left sub-tree of this node is the left part, right sub-tree of this node is the right part. This problem can be solved following //this logic.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        return buildTreeRecursion(preorder, inorder, 0, 0, inorder.size() - 1);
        
    }
private:
    TreeNode *buildTreeRecursion(vector<int>& preorder, vector<int> &inorder, int pre_beg, int in_beg, int in_end) {
        TreeNode * new_node = new TreeNode (preorder[pre_beg]);//每次迭代都用pre_beg的值创造一个node
        int i;
    
        if (in_beg > in_end) {//终止条件
            return nullptr;
        }
        for (i = in_beg; i <= in_end; i++) {//找到创造的新结点对应的inorder里的索引位置，i左边是左子树，i右边是右子树
            if (preorder[pre_beg] == inorder[i]) {
                break;
            }
        }
        new_node->left = buildTreeRecursion(preorder, inorder, 
                pre_beg + 1, in_beg, i - 1);
        new_node->right = buildTreeRecursion(preorder, inorder, //i - in_beg是inorder里左子树的结点个数
                pre_beg + i - in_beg + 1, i + 1, in_end);//因为preorder里右子树一定在左子树之后，所以可以界定右子树在preorder里的位置
                
        return new_node;
    }
};

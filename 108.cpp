/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //根本不用去想复杂的二叉树旋转操作，题目没说按照从低到高的顺序制作AVL树
 //只需要满足平衡条件即可，得到的AVL树按照插入的顺序不同可以不止有一种，只要高度平衡就好
 //测试的时候估计是比较高度差是否小于等于1
 //所以这题用vecotr的一半分开左右子树递归完成
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode *helper(vector<int> &nums, int v_beg, int v_end) {
        if (v_beg > v_end) {
            return nullptr;
        }
        int mid = (v_beg + v_end) / 2;
        TreeNode *new_node = new TreeNode(nums[mid]);//以此结点为根节点，划分左右子树
        
        new_node->left = helper(nums, v_beg, mid - 1);
        new_node->right = helper(nums, mid + 1, v_end);
        
        return new_node;
    }

};

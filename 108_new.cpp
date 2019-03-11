class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode *helper(vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + ((end - start) >> 1);
        auto curNode = new TreeNode(nums[mid]);
        curNode->left = helper(nums, start, mid - 1);
        curNode->right = helper(nums, mid + 1, end);
        return curNode;
    }
};

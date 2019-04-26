class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //从两个方向各遍历一次数组，计算出i之前/i之后的元素乘积
        vector<int> res(nums.size(), 0);
        int multi = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = multi;
            multi *= nums[i];
        }
        multi = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= multi;
            multi *= nums[i];
        }
        return res;
    }
};

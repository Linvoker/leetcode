//状态转移方程local_max(i) = max{local_max(i - 1) + nums[i], nums[i]},local_max是以第i位结尾(包含第i位)的最大子序列
//要想找到第i位结尾(不一定会包含i)的最大子序列,只需要找local_max(1)...local_max(i)的最大值就好了
//这个算自顶向下吧
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> table (nums.size(), INT_MIN);
        int count = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            count = std::max(localMax(nums, i, table), count);
        } 
        return count;
    }
    int localMax(vector<int> &nums, int i, vector<int> &table) {
        if (i == 0) {
            return nums[0];
        }
        if (table[i] == INT_MIN) {
            return table[i] = std::max(localMax(nums, i - 1, table) + nums[i], nums[i]);
        } else {
            return table[i];
        }
    }
};

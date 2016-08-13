//这题方法和300. Longest Increasing Subsequence基本一样,但是更复杂在用bool mark标示了该增还是该减
//https://leetcode.com/problems/longest-increasing-subsequence/
//状态转移方程:table[i] = max{1 + table[j]}; 0<=j<i && nums[i]满足wiggle条件(mark==true时nums[i]<nums[i-1])
//table[i]记录0到i范围内包含nums[i]的最长wiggle子序列
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> table(nums.size(), -1);
        bool mark = true;
        int ret_max = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] < nums[i - 1]) {
                mark = true;
            } else {
                mark = false;
            }
            ret_max = std::max(ret_max, helper(nums, mark, table, i));
        }
        return ret_max;
    }
    int helper(vector<int> &nums, bool mark, vector<int> &table, int i) {
        if (i == 0) {
            return 1;
        }
        if (table[i] != -1) {
            return table[i];
        }
        int max_count = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (mark == true) {
                if (nums[i] < nums[j]) {
                    max_count = std::max(max_count, 1 + helper(nums, !mark, table, j));
                } else {
                    continue;
                }
            } else {
                if (nums[i] > nums[j]) {
                    max_count = std::max(max_count, 1 + helper(nums, !mark, table, j));
                } else {
                    continue;
                }
            }
        }
        return table[i] = max_count;
    }
};

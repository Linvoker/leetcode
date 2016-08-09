//先用递归的想法整理出状态转移方程:f(i) = max{f(i - 2) + nums[i], f(i - 1)} (i >= 2) ; 两个边界条件f(0) = nums[0]; f(1) = max{nums[0], nums[1]};
//其实这题如果用自底向上的方法就不用O(n)的空间复杂度来存表格了.并且因此会更快
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> table;
        return helper(nums, nums.size() - 1, table);
    }
    int helper(vector<int> &nums, int index, unordered_map<int, int> &table) {
        if (index == 0) {//边界条件
            return nums[0];
        } else if (index == 1) {//边界条件
            return std::max(nums[0], nums[1]);
            
        } else if (table.find(index) != table.end()) {//子问题重叠
            return table[index];
        } else {//状态转移方程
            return table[index] = std::max(helper(nums, index - 2, table) + nums[index], helper(nums, index - 1, table));
        }
    }
};

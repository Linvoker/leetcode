//依旧是利用198. House Robber的解决办法来解决.
//Rob houses 0 to n - 2;
//Rob houses 1 to n - 1.
//然后取他们的最大值即可
//自顶向下
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> table;
        unordered_map<int, int> table1;//这里需要换一个table,否则会出现问题
        return std::max(helper(nums, 0, nums.size() - 2, table), helper(nums, 1, nums.size() - 1, table1));
        
    }
    int helper(vector<int> &nums, int begin, int index, unordered_map<int, int> &table) {
        if (index == begin + 1) {//边界条件
            return std::max(nums[begin], nums[begin+1]);
        } 
        if(index == begin) {//边界条件
            return nums[begin];
        }
        if (table.find(index) != table.end()) {//子问题重叠
            return table[index];
        } else {//状态转移方程
            return table[index] = std::max(helper(nums, begin, index - 2, table) + nums[index], helper(nums, begin, index - 1, table));
        }
    }
};
    

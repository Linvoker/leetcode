//这题我做了很久很久,因为这题有点绕
//table[i]记录0到i范围内包含nums[i]的最长递增子序列,table[i] = max{table[j] + 1};当j < i && nums[j] < nums[i].
//要想求出真正的最长递增子序列,就要计算max{table[j]}, 0 <= j <= n
//这题其实和53. Maximum Subarray一个道理
//这题我只做O(N^2)的时间复杂度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> table(nums.size(), -1);
        int ret_max = INT_MIN;
        for (int i = 0; i <= nums.size() - 1; i++) {
            ret_max = std::max(ret_max, helper(nums, table, i));
        }
        return ret_max;
    }
    int helper(vector<int> &nums, vector<int> &table, int i) {
        if (i == 0) {
            return table[0] = 1;
        }
        
        if (table[i] != -1) {
            return table[i];
        }   
        int max_count = 1;
        for(int j = i - 1; j >= 0; j--) {
            
            if (nums[j] < nums[i]) {
                max_count = std::max(max_count, 1 + helper(nums, table, j));
            } 
        }
        return table[i] = max_count;
    }
};

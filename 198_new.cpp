class Solution {
public:
    //P(i) = max(f(i) + P(i+2), P(i+1))
    /*int rob(vector<int>& nums) {
        vector<int> table(nums.size(), -1);
        return dp(nums, 0, table);
    }
    int dp(vector<int>& nums, int pos, vector<int> &table) {
        if (pos == nums.size() - 1) {
            return nums[pos];
        }
        if (pos == nums.size()) {
            return 0;
        }
        if (table[pos] != -1) {
            return table[pos];
        }
        
        return table[pos] = max(nums[pos] + dp(nums, pos + 2, table), dp(nums, pos + 1, table));
    }*/
    //P(i) = max(P(i+1), f(i) + P(i+2))
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0; //P(i+1)
        int right = 0;//P(i+2)
        for (int i = nums.size() - 1; i >= 0 ; i--) {
            int tmp = left;
            left = max(left, nums[i] + right);
            right = tmp;
        }
        return left;
    }
};

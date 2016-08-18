//nums[n] > 0时:ma(n) = ma(n - 1) > 0 ? ma(n - 1) * nums[n] : nums[n]//ma(n)为以n为截止的乘数里包括nums[n]的最大积
//              mi(n) = mi(n - 1) <= 0 ? mi(n - 1) * nums[n] : nums[n]//mi(n)为以n为截止的乘数里包括nums[n]的最大积
//nums[n] < 0时:ma(n) = mi(n - 1) <= 0 ? mi(n - 1) * nums[n] : nums[n]//
//              mi(n) = ma(n - 1) > 0 ? ma(n - 1) * nums[n] : nums[n]//
//nums[n] == 0时:ma(n) = mi(n) = 0//

//需要用的状态转移方程要求两个值,一个ma,一个mi,用自底向上更方便,否则还要返回一个ma(n - 1)一个mi(n - 1)
//O(n)的空间复杂度,O(n)的时间复杂度
/*class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> table(nums.size(), {INT_MIN, INT_MIN});//first保存ma,second保存mi
        table[0].first = nums[0];
        table[0].second = nums[0];
        int ret_val = nums[0];
        for (int i = 1; i < nums.size(); i++) {//找到ma(0)~ma(n)的最大值即为product最大值
            if (nums[i] > 0) {
                table[i].first = table[i - 1].first > 0 ? table[i - 1].first * nums[i] : nums[i];
                table[i].second = table[i - 1].second <= 0 ? table[i - 1].second * nums[i] : nums[i];
            } else if (nums[i] < 0) {
                table[i].first = table[i - 1].second <= 0 ? table[i - 1].second * nums[i] : nums[i];
                table[i].second = table[i - 1].first > 0 ? table[i - 1].first * nums[i] : nums[i];
            } else {
                table[i] = {0, 0};
            }
            ret_val = std::max(ret_val, table[i].first);
        }
        return ret_val;
    }
    
    
};*/
//O(1)空间复杂度,O(n)时间复杂度
//有上面直接改的
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_max = nums[0];
        int pre_min = nums[0];
        int cur_max = 0;//cur_的初始化不重要
        int cur_min = 0;
        int ret_val = nums[0];
        for (int i = 1; i < nums.size(); i++) {//找到ma(0)~ma(n)的最大值即为product最大值
            if (nums[i] > 0) {
                cur_max = pre_max > 0 ? pre_max * nums[i] : nums[i];
                cur_min = pre_min <= 0 ? pre_min * nums[i] : nums[i];
            } else if (nums[i] < 0) {
                cur_max = pre_min <= 0 ? pre_min * nums[i] : nums[i];
                cur_min = pre_max > 0 ? pre_max * nums[i] : nums[i];
            } else {
                cur_max = cur_min = 0;
            }
            ret_val = std::max(ret_val, cur_max);
            
            pre_max = cur_max;
            pre_min = cur_min;
        }
        return ret_val;
    }
    
    
};

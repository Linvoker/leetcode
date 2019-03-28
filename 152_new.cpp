#include<vector>
#include<iostream>
#include<stack>
#include<string>
//#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    //状态转移方程如下:(没有152.cpp列的那么麻烦)
    // ma(x) = max(f(x), mi(x+1) * f(x), ma(x+1) * f(x))
    // mi(x) = min(f(x), mi(x+1) * f(x), ma(x+1) * f(x))
    /*int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> table_ma(nums.size(), INT_MIN);
        vector<int> table_mi(nums.size(), INT_MAX);
        for (int i = 0; i < nums.size(); i++) {
            dp(nums, i, table_mi, table_ma);
            res = max(res, table_ma[i]);
        }
        return res;
    }
    void dp(vector<int> &nums, int i, vector<int> &table_mi, vector<int> &table_ma) {
        if (table_ma[i] != INT_MIN) {
            return;
        }
        if (i == nums.size() - 1) {
            table_ma[i] = table_mi[i] = nums[i];
            return;
        }
        dp(nums, i + 1, table_mi, table_ma);
        table_ma[i] = max(nums[i], max(nums[i] * table_mi[i+1], nums[i] * table_ma[i+1]));
        table_mi[i] = min(nums[i], min(nums[i] * table_mi[i+1], nums[i] * table_ma[i+1]));
        return;
    }*/
    //又上面改写 自底向上
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> table_ma(nums.size(), INT_MIN);
        vector<int> table_mi(nums.size(), INT_MAX);
        int last_min = 0, cur_min = 0, last_max = 0, cur_max = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                cur_min = cur_max = nums[i];
            } else  {
                cur_min = min(nums[i], min(nums[i] * last_min, nums[i] * last_max));
                cur_max = max(nums[i], max(nums[i] * last_min, nums[i] * last_max));
                //dp(nums, i, table_mi, table_ma);
            }
            res = max(res, cur_max);

            last_min = cur_min;
            last_max = cur_max;
        }
        return res;
    }
};
int main() {
    vector<int> nums{-4,-3,-2};
    cout << (new Solution)->maxProduct(nums) << endl;
}

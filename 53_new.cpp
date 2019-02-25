#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    //详见53.cpp
    int maxSubArray(vector<int>& nums) {
        int resmax = INT_MIN;
        vector<int> table(nums.size(), INT_MIN);
        for (unsigned int i = 0; i < nums.size(); i++) {
            resmax = max(resmax, dp(i, nums, table));     
        }
        return resmax;
    }
    int dp(int i, vector<int>& nums, vector<int> &table) {
        if (i == (int)nums.size()) {
            return 0;
        }
        if (table[i] != INT_MIN) {
            return table[i];
        }  else {
            return table[i] = max(dp(i + 1, nums, table) + nums[i], nums[i]);
        }
    }
};
int main() {
    //cout << (new Solution)->myPow(4, -3) << endl;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << (new Solution)->maxSubArray(nums) << endl;
}

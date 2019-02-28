#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>

using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> trace{};
        backTracking(nums, trace, 0, res);
        return res;
    }
    void backTracking(vector<int>& nums, vector<int> &trace, int start, vector<vector<int>> &res) {
        res.push_back(trace);
        for (int i = start; i < nums.size(); i++) {
            trace.push_back(nums[i]);
            
            backTracking(nums, trace, i + 1, res);
            
            trace.pop_back();
        }
    }
};
int main() {
    vector<int> nums {1,2,3};
    auto shit = (new Solution)->subsets(nums);
    return 0;
}

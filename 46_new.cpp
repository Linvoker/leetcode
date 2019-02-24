#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> trace;//参与回溯的vector
        vector<vector<int>> res;//储存结果
        unordered_set<int> set; //构建trace时已经用过的元素
        backTrace(nums, set, trace, res);
        return res;
    }
    void backTrace(vector<int>& nums, unordered_set<int> &set, vector<int> &trace, vector<vector<int>> &res) {
        if (trace.size() == nums.size()) { //终止条件
            res.push_back(trace);
            return;
        }
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) { //剪枝函数
                continue;
            } else {
                set.insert(nums[i]); 
            }
            trace.push_back(nums[i]);
            backTrace(nums, set, trace, res);
            trace.pop_back();
            set.erase(nums[i]);
        }
        return;
    }
};
int main() {

    vector<int> nums {1,2,3};
    vector<vector<int>> res = (new Solution())->permute(nums);
    return 0;
}

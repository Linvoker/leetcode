class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res{};
        vector<int> trace{};
        sort(nums.begin(), nums.end());
        backTracking(nums, trace, 0, res);
        return res;
    }
    void backTracking(vector<int>& nums, vector<int> &trace, int start, vector<vector<int>> &res) {
        res.push_back(trace);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) { //用这个剪枝函数来避免同一层节点的重复
                continue;
            }
            trace.push_back(nums[i]);
            
            backTracking(nums, trace, i + 1, res);
            
            trace.pop_back();
        }
    }
};

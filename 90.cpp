//参考78. Subsets
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret_vec;
        vector<int> trace;
        std::sort(nums.begin(), nums.end());
        backTracking(ret_vec, trace, nums, 0);
        return ret_vec;
    }
    void backTracking(vector<vector<int>> &ret_vec, vector<int> &trace, const vector<int> &candidates, int begin) {
        //终止条件就是无条件
        ret_vec.push_back(trace);
        for (int i = begin; i < candidates.size(); i++) {
            if (i != begin && candidates[i] == candidates[i - 1]) {//剪枝函数
                continue;
            }
            trace.push_back(candidates[i]);
            
            backTracking(ret_vec, trace, candidates, i + 1);
            
            trace.pop_back();
        }
    }
};

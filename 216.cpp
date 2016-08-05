//这个问题应该是39.combination sum和40.combination sum ii的中和版,是最简单的了。这题和77. Combinations最像了
//此题candidates本身不包含重复元素，candidates[]每个元素只能使用一次，ret_vec不包含重复数组,但是此题有规定trace的数量k
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, candidates, k, n, 0);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, 
             const vector<int> &candidates, const int k, int target, int begin) {
        if (trace.size() == k && target == 0) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin; i <= candidates.size() - 1; i++) {
            if (trace.size() == k || target < candidates[begin]) {
                return;
            }
            trace.push_back(candidates[i]);
            backTracing(ret_vec, trace, candidates, k, target - candidates[i], i + 1);
            trace.pop_back();
        }
    }
};

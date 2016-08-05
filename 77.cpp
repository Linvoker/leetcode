//n是candidates的个数，k是解空间的高度
//此题candidates本身不包含重复元素，candidates[]每个元素只能使用一次，ret_vec不包含重复数组,但是此题有规定trace的数量k
//和216. Combination Sum III最相似

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {//backtrace 的解空间高度为k
        vector<int> candidates;
        vector<vector<int>> ret_vec;
        vector<int> trace;
        
        int i = 1;
        while (n--) {
            candidates.push_back(i++);//{1, 2, 3, ...n}
        }
        backTracing(ret_vec, trace, candidates, k, 0);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, 
             const vector<int> &candidates, const int k, int begin) {
        if (k == trace.size()) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin; i <= candidates.size() - 1; i++) {
            //因为要遍历全部可能性，所以根本没有剪枝函数
            trace.push_back(candidates[i]);
            backTracing(ret_vec, trace, candidates, k , i + 1);
            trace.pop_back();
        }
        return;
    }
};

//a set of，set表示这是数学上含有不重复元素的集合，a collection of ,collection表示这是数学上含有重复元素的集合
//参考40. Combination Sum II
//此题candidates本身不包含重复元素，candidates[]任意元素能使用多次，ret_vec不包含重复数组

//这个方法313ms，重写吧
/*class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, candidates, target);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> &candidates, int target) {
        if (target == 0) {//问题在递归终止函数
            vector<int> temp = trace;
            sort(temp.begin(), temp.end());
            if (find(ret_vec.begin(), ret_vec.end(), temp) == ret_vec.end()) {
                ret_vec.push_back(temp);
            }
            return;
        }
        for (auto v : candidates) {
            if (target < 0) {
                return;
            }
            trace.push_back(v);
            backTracing(ret_vec, trace, candidates, target - v);
            trace.pop_back();
            
        }
    }
};*/
//64ms。缩小规模，改善剪枝函数，如果当前打算加入trace的值大于原本trace的最后一个值，则换值加入（continue）。
//也就是为了避免重复我们可以不用每次都排序然后再查找trace是否已经再ret_vec里，每次加入到trace的元素都因为剪枝函数2按从小到大加入，这样就不用那么麻烦了
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, candidates, target);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> &candidates, int target) {
        if (target == 0) {
            ret_vec.push_back(trace);
            return;
        }
        
        for (auto v : candidates) {
            if (target < 0) {//剪枝函数
                return;
            }
            if (!trace.empty() && trace.back() > v) {//同为剪枝函数
                continue;
            }
            trace.push_back(v);
            backTracing(ret_vec, trace, candidates, target - v);
            trace.pop_back();
            
        }
        return;
    }
};
/*
//这个并非我想到的，这是这一系列问题的模板。先sort一遍candidates，用begin记录candidates当前的索引，直接按从小到大的路径走，比上一个方法还省时16ms。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret_vec;
        vector<int> trace;
        std::sort(candidates.begin(), candidates.end());
        backTracing(ret_vec, trace, candidates, target, 0);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> &candidates, int target, int begin) {
        if (target == 0) {
            ret_vec.push_back(trace);
            return;
        }
        
        for (int i = begin; i <= candidates.size() - 1; ++i) {
            if (target < candidates[i]) {//剪枝函数
                return;
            }
            trace.push_back(candidates[i]);
            backTracing(ret_vec, trace, candidates, target - candidates[i], i);
            trace.pop_back();
            
        }
        return;
    }
};

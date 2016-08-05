//a set of，set表示这是数学上含有不重复元素的集合，a collection of ,collection表示这是数学上含有重复元素的集合
//此题candidates本身包含重复元素，candidates[]的每个元素只能使用一次，ret_vec不包含重复数组

//从小到大加入vector<int>以防止出现内部元素顺序不同实际重复的vector<int>,可以用两种方法（先排序用int begin或者先不排序见39. Combination Sum），但是
//因为有重复元素，所以最好先排序，因为这样每次for()的时候跳过candidates里等于前一个元素的元素或者
//每次vector<vector<int>>::push_back()的时候只用和前一个元素比较就可以判断此元素重没重复。
//如果不先排序很难消除内部顺序相同而产生重复的vector<int>
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, candidates, target, 0);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, 
             const vector<int> &candidates, int target, int begin) {
        if (target == 0) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin; i <= candidates.size() - 1; i++) {
            if (target < candidates[i]) {//剪枝函数
                return;
            }
            if (i != begin && candidates[i] == candidates[i - 1]) {//剪枝函数//i != begin这句很重要，列个数组看看就知道了
                continue;
            }
            trace.push_back(candidates[i]);
            backTracing(ret_vec, trace, candidates, target - candidates[i], i + 1);//这里必须i+1
            trace.pop_back();
        }   
        return;
    }
};

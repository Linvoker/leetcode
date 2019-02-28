//能通过剪枝函数的都能通过终止条件，终止条件只是将结果写入ret_vec，并不return，这点要注意
//这题和以往的模式不一样，有点例外，但框架一样

//第二次想到的办法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracking(ret_vec, trace, nums, 0);
        //ret_vec.push_back({});
        return ret_vec;
    }
    void backTracking(vector<vector<int>> &ret_vec, vector<int> &trace, const vector<int> &candidates, int begin) {
        //if (!trace.empty()) {//终止条件（其实就是无条件除了第一此不push_back，其他时候都做了）
            ret_vec.push_back(trace);
        //}
        for (int i = begin; i < candidates.size(); i++) {
            
            //剪枝函数也没有，因为有begin
            trace.push_back(candidates[i]);
                
            backTracking(ret_vec, trace, candidates, i + 1);
                
            trace.pop_back();
    
        }
        return;
    }
};

//4ms，8ms，10ms最初想到的办法，没有上面的直观
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracking(ret_vec, trace, nums);
        ret_vec.push_back({});
        return ret_vec;
    }
    void backTracking(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> &candidates) {
        if (!trace.empty()) {//终止条件
            ret_vec.push_back(trace);
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (!trace.empty() && trace[trace.size() - 1] > candidates[i]) {//剪枝函数
                continue;
                
            }
                trace.push_back(candidates[i]);
                
                vector<int> temp = candidates;
                temp.erase(temp.begin() + i);//消耗线性时间
                backTracking(ret_vec, trace, temp);
                
                trace.pop_back();
            
    
        }
        return;
    }
};

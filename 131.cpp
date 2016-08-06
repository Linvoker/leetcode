//这算是另一种模式的backtracking了
//https://discuss.leetcode.com/topic/6186/java-backtracking-solution/2
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret_vec;
        vector<string> trace;
        backTracking(ret_vec, trace, s, 0);
        return ret_vec;
    }
    void backTracking(vector<vector<string>> &ret_vec, vector<string> &trace, const string &candidates, int begin) {
        if (begin == candidates.size()) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {//这个同一水平的迭代有点和以往不一样
            if (!isPalindrome(candidates, begin, i)) {//回文链表有点麻烦要用2个指针以不同速度找到中点，再反转后半部分。但string就简单多了
                continue;
            }
            
            string temp;
            for (int k = begin; k <= i; k++) {
                temp.push_back(candidates[k]);
            }
            trace.push_back(temp);
            
            backTracking(ret_vec, trace, candidates, i + 1);
    
            trace.pop_back();
        
            
        }
        return;
    }
    bool isPalindrome(const string &candidates, int begin ,int end) {//这个end是包括在回文内的
        while(begin < end) {
            if (candidates[begin++] != candidates[end--]) {
                return false;
            }
        }
        return true;
    }
};

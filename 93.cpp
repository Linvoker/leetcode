//这题的解空间模式和131. Palindrome Partitioning一样
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret_vec;
        string trace;
        backTracking(ret_vec, trace, s, 0, 0);
        return ret_vec;
    }
    void backTracking(vector<string> &ret_vec, string &trace, const string &candidates, int begin, int count) {
        if (count == 4) {//终止函数
            if (begin == candidates.size()) {//试试
                ret_vec.push_back(trace);
            }
            return;
        }
        for (int i = begin; i < begin + 3 && i < candidates.size(); i++) {
            if (i > begin && candidates[begin] == '0') {//剪枝函数
                return;
            }
            if (i == begin + 2) {//剪枝函数
                //string temp(candidates.begin() + begin, candidates.begin() + i + 1);//注意！第二个参数是最后一个元素的下一位的迭代器
                string temp(candidates, begin, 3);//string的构造函数
                if (std::stoi(temp) > 255) {
                    return;
                }
            }
            
            int move = begin;
            for ( ; move <= i; move++) {
                trace.push_back(candidates[move]);
            }
            if (move != candidates.size()) {//非最后一位才要加点给下一端数字
                trace.push_back('.');
            }
            
            backTracking(ret_vec, trace, candidates, move, count + 1);
            
            if (move != candidates.size()) {
                trace.pop_back();
            }
            for (move = begin; move <= i; move++) {
                trace.pop_back();
            }
            
        }
    }
};

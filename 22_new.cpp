#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string trace = "";
        vector<string> res{};
        int left_num = 0, right_num = 0;
        traceBack(trace, res, left_num, right_num, n);
        return res;
    }
    void traceBack(string &trace, vector<string> &res, int left_num, int right_num, int n) {
        if (trace.size() == (size_t)(n * 2)) { //终止条件
            if (left_num == n) {
                res.push_back(trace);
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (left_num < right_num || left_num == n+1) { //剪枝函数
                return;
            }
            
            if (i == 0) {
                trace.push_back('(');
                traceBack(trace, res, left_num + 1, right_num, n);
            } else if (i == 1) {
                trace.push_back(')');
                traceBack(trace, res, left_num, right_num + 1, n);
            }
            trace.pop_back();
        }
        return;
    }

    //用了栈判断是否是全闭合的括号。不是一个好方法(没有剪枝函数，太慢了)。参考22.cpp
    // vector<string> generateParenthesis(int n) {
        // string trace_str = "";
        // stack<char> trace_stk;
        // vector<string> res{};
        // traceBack(trace_str, trace_stk, res, 0, n*2);
        // return res;
    // }
    // void traceBack(string trace_str, stack<char> trace_stk, vector<string> &res, const int level, const int max_level) {
        // if (level == max_level) { //终止条件
            // if (trace_stk.empty()) {
                // res.push_back(trace_str);
            // }
            // return;
        // }
        // trace_stk.push('(');
        // trace_str.push_back('(');
        // traceBack(trace_str, trace_stk, res, level+1, max_level);
        // trace_str.pop_back();
        // trace_stk.pop();

        // if (!trace_stk.empty() && trace_stk.top() == '(') {
            // trace_stk.pop();
        // } else {
            // return;
        // }
        // trace_str.push_back(')');
        // traceBack(trace_str, trace_stk, res, level+1, max_level);
        // trace_str.pop_back();
        // return;
    // }

};
int main () {
    Solution x;
    auto res = x.generateParenthesis(3);
    for (unsigned int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

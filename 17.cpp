//backtrace问题的模板
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> v_str = {"", "-1", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret_vec;
        string trace_str;
        backTracing(ret_vec, trace_str, v_str, digits, 0);
        return ret_vec;
    }
    void backTracing(vector<string> &ret_vec, string &trace_str, const vector<string> &v_str, const string &digits, int digit_index) {
        if (digit_index > digits.size() - 1) {
            ret_vec.push_back(trace_str);
            return;
        }
        for (int i = 0; i <= v_str[digits[digit_index] - '0'].size() - 1; i++) {
            trace_str.push_back(v_str[digits[digit_index] - '0'][i]);
            backTracing(ret_vec, trace_str, v_str, digits, digit_index + 1);
            trace_str.pop_back();
        }
    }
};

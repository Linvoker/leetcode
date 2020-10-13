#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> dict = {"", "" ,"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>{};
        }
        vector<string> res;
        string trace = "";
        backTrace(digits, 0, trace, res); 
        return res;
    }
    void backTrace(string &digits, int pos, string trace, vector<string> &res) {
        if (pos == digits.length()) {
            res.push_back(trace);
            return;
        }
        string curLevel = this->dict[digits[pos] - '0'];
        for (auto c : curLevel) {
            trace.push_back(c);
            backTrace(digits, pos + 1, trace, res);
            trace.pop_back();
        }
    }
};
int main() {
    auto x = (new Solution)->letterCombinations("213");
    for (int i = 0; i < x.size(); i++) {
        cout<< x[i] <<endl;
    }
}

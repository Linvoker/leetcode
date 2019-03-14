#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.length() == 0) {
            return vector<vector<string>> {};
        }
        vector<vector<string>> res;
        vector<string> trace;
        backTrack(s, 0, res, trace);
        return res;
    }
    void backTrack(string &s, int pos, vector<vector<string>> &res, vector<string> &trace) {
        if (pos >= s.length()) {
            res.push_back(trace);
            return;
        }
        for (unsigned int i = pos; i <= s.length(); i++) {
            if (isPalindrome(s, pos, i)) {
                trace.push_back(s.substr(pos, i - pos + 1));
                backTrack(s, i + 1, res, trace);
                trace.pop_back();
            }
        }
        return;
    }
    //TODO 加记录
    bool isPalindrome(string &s, int start, int end) {
        if (start >= end) {
            return true;
        }
        return s[start] == s[end] && isPalindrome(s, start + 1, end - 1);
    }
};
int main () {
    (new Solution)->partition("aab");
    return 0;
}

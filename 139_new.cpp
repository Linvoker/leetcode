#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> table(s.length(), -1);
        return backTrack(s, 0, wordDict, table);
    }
    //这个方准准确的说应该是dfs+dp，打表记录start位置是否能走通
    bool backTrack(const string &s, int start, vector<string>& wordDict, vector<int>& table) {
        if (start == s.size()) { //大于也不行，一定要刚刚好
            return true;
        }
        if (table[start] != -1) {
            return table[start] == 1;
        }
        for (auto word : wordDict ) {
            int w_size = word.length();
            if (s.compare(start, w_size, word) != 0) {
                continue;
            }
            if (backTrack(s, start + w_size, wordDict, table) == false) {
                continue;
            } else {
                table[start] = 1;
                return true;
            }
        }
        table[start] = 0;
        return false;

    }
};
int main () {
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout <<(new Solution)->wordBreak(s, wordDict) << endl;
}

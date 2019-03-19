#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
        //vector<int> table(s.length(), -1);
        unordered_map<int, vector<string>> table;
        vector<string> res;
        string trace;

        backTrack(s, 0, wordDict, trace, res, table);
        return res;
    }
    //这个方准准确的说应该是dfs+dp，打表记录start位置是否能走通
    vector<string> backTrack(const string &s, int start, vector<string>& wordDict, string trace, vector<string> &res, unordered_map<int, vector<string>> &table) {
        if (start == s.size()) { //大于也不行，一定要刚刚好
            res.push_back(trace);
            return vector<string>{""};
        }
        if (table.find(start) != table.end()) { //有
            return table[start];
        }

        for (auto word : wordDict ) {
            int w_size = word.length();
            if (s.compare(start, w_size, word) != 0) {
                continue;
            }
            string tmp = trace;
            if (start != 0) {
                tmp += ' ';
            }
            tmp += word;

            vector<string> vs = backTrack(s, start + w_size, wordDict, tmp, res, table);
            for (auto str : vs) {
                res.push_back(str.insert(0, tmp));
                table[start].push_back(str.substr(trace.size()));
            }
        }

        return table.find(start) == table.end() ? vector<string>{} : table[start];

    }
};
int main () {
    string s = "catsanddog";
    vector<string> shit = {"cat","cats","and","sand","dog"};
    (new Solution)->wordBreak(s, shit);
    return 0;
}

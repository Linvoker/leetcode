#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> table = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
        return backTrace(digits, table);

    }
    vector<string> backTrace(string digits, vector<string> &table) {

        if (digits.length() == 1) {
            vector<string> res{};
            string tmp = table[stoi(digits.substr(0, 1))];
            for (unsigned int i = 0; i < tmp.length(); i++) {
                res.push_back(table[stoi(digits.substr(0, 1))].substr(i, 1));
                //cout << table[stoi(digits.substr(0, 1))].substr(i, 1) << endl;
            }
            return res;
        }

        vector<string> shit = backTrace(digits.substr(1, string::npos), table);
        string tmp = table[stoi(digits.substr(0, 1))];
        vector<string> res{};
        for (unsigned int i = 0; i < tmp.length(); i++) {
            for (unsigned int j = 0; j < shit.size(); j++) {
                res.push_back(tmp.substr(i, 1) + shit[j]); 
            }
        }
        return res;
    }
};
int main() {
    Solution x;
    auto shit = x.letterCombinations("23");
    for (auto it = shit.begin(); it < shit.end(); it++ ) {
        cout << *it << endl; 
    }
}

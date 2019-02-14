#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) {
            return "";
        }
        int minLen = INT_MAX;
        for (int i = 0; i < size; i++) { //先确认vector中最短string的长度 方便退出下面的循环
            minLen = min(minLen, (int)strs[i].length()); 
        }
        long int i = 0;
        while(i < minLen) {
            char curChar = 0;
            int j = 0;
            for (; j < size; j++) { //vector里逐个string比较指定位置的字符
                if (curChar == 0) {
                    curChar = strs[j][i];
                }
                if (curChar != strs[j][i] ) {
                    goto shit;
                }
            }
            i++;
        }
shit:
        return strs[0].substr(0, i);
    }
};
int main () {
    Solution x;
    //vector<string> y = {};
    vector<string> y = {"flower","flow","flight"};
    cout << x.longestCommonPrefix(y) << endl;
}

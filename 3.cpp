#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters
//利用滑动窗口做 时间复杂度O(n)
//char 0-256即可表示，用vector不用unordered_map可以省时间
//指针j遍历字符串，若从未出现过(不在vector里)，cnt++ && 更新maxCnt
//若干出现过j指向的字符，则i指针移动到上一个该字符的下一位，继续走j
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, 0);
        int maxCnt = 0, cnt = 0; //cnt用来记录每个以i为首的窗口的大小
        for (unsigned int i = 0, j = 0; j < s.length(); j++) {
            if (dict[s[j]] > 0) {
                while (s[i] != s[j]) {
                    dict[s[i++]] = 0;
                    cnt--;
                }
                i++;
            } else {
                //不在dict里则更新最大值继续
                dict[s[j]] = 1;
                maxCnt = max(maxCnt, ++cnt);
                //continue;
            }
        }
        return maxCnt; 
    }
};

int main () {
    Solution x;
    int y = x.lengthOfLongestSubstring("abcabcbb");
    cout << "a:" << y << endl;
}

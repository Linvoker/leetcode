#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //思路:自顶向上动态规划。
    //暴力解法：f(i,j)表示字符串s[i]~s[j]是否一个回文，找到j-i最大的字符串即可。
    //          用O(n^2)找出所有i,j的组合，判断一个f(i,j)需要O(n)，一共需要O(n^3)
    //动态规划:打表记下之前已经记录过的f(i,j)，空间复杂度会很大O(n^2)，设置步长gap = j - i。
    //          gap=n时只需要依赖gap=n-2产生的f(i,j)结果。故空间复杂度可缩减为O(n)。
    //          因为每次步长+2，所以奇数步长和偶数步长都得走一遍，找到最大的步长即可
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        string res = "";
        int max_gap = -1;
        int left, right = 0;
        for (int gap = 0; gap < 2; gap++) {
            int cur_gap = gap;
            vector<int> vi(s.length(), -1);
            while (cur_gap <= (int)s.length() - 1) {
                for (int i = 0, j = i + cur_gap; j < s.length(); i++, j++) {
                    if (j - i <= 1) { //一个字符、两个字符
                        vi[i] = s[i] == s[j] ? 1 : 0;
                    } else {
                        vi[i] = vi[i + 1] == 1 && s[i] == s[j] ? 1 : 0;
                    }
                    if (vi[i] == 1 && cur_gap > max_gap) {
                        left = i; right = j;
                        max_gap = cur_gap;
                    }

                }
                cur_gap += 2;
            }
        }
        res = s.substr(left, right - left + 1);
        return res;
    }
};
int main(){
    cout << (new Solution)->longestPalindrome("babad") << endl;
}

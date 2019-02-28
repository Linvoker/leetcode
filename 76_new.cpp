#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>

using namespace std;
class Solution {
public:
    //求子字符串window的模板
    int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
    }
    //解答:https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }
        vector<int> table(128, 0);
        for (auto c : t) {
            table[c]++;
        }
        int t_len = t.length();
        int cnt = 0; //遇到t里字符的次数
        int res_head = 0; //最短子串的头
        int res_len = INT_MAX; //最短子串的长度
        string res = "";
        int length = s.length();
        int slow = 0, fast = 0;
        while (fast < length) {
            if (table[s[fast++]]-- > 0) { //处理快指针 所有元素都包含才开始处理慢指针
                cnt++;
            }
            while (cnt == t_len) { //处理慢指针 作用:一直往前走试探出最短的有效长度
                if (res_len > fast - slow) {
                    res_len = fast - slow;
                    res_head = slow;
                }
                if (table[s[slow++]]++ >= 0) {
                    cnt--;
                }
            }

        }
        if (res_len != INT_MAX) {
            res = s.substr(res_head, res_len);
        }
        return res;
    }
};
int main () {
    cout << (new Solution)->minWindow("ab", "a") << endl;
}

#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, cur_len = 0;
        vector<int> vi(256, -1);
        for (int i = 0; i < s.length(); i++) {
            if (vi[s[i]] == -1) {
                cur_len++;
                max_len = max(max_len, cur_len);
            } else {
                for (int j = i - cur_len; j < vi[s[i]]; j++) {
                    cur_len--;
                    vi[s[j]] = -1;
                }
            }

            vi[s[i]] = i;
        }
        return max_len;
    }
    */
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        vector<int> vi(256, -1);
        //i 窗口右边界，j 窗口左边界
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (vi[s[i]] >= j) {
                j = vi[s[i]] + 1; //更新左边界
            } 
            vi[s[i]] = i;
            max_len = max(max_len, i - j + 1); 
        }
        return max_len;
    }
};
int main ()
{
    cout << (new Solution)->lengthOfLongestSubstring(" ") << endl;
}

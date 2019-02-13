#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 自底向上动态规划 O(N^2)
     */
    string longestPalindrome(string s) {
       if (s == "") {
           return "";
       }
        int len = s.length();
        //string res = "";
        vector<vector<int> > dict(len, vector<int>(len, 0));
        int gap = 0; //start end的跨度
        int start = 0, end = 0;
        while (gap++ < len) {
            for (int i = 0, j = i + gap; j < len; i++, j++) {
                if (s[i] == s[j] && (i + 2 == j || i + 1 == j || dict[i+1][j-1] == 1)) {
                    //两个字符或三个字符看s[ij]是否相等，多个字符看s[ij]是否相等并且内部包含回文
                    dict[i][j] = 1;

                    start = i; end = j;
                }
            }
        }
        // for (int i = 0; i < len; i++) {
            // for (int j = 0; j < len; j++) {
                // cout << dict[i][j] << " ";
            // }
            // cout << endl;
        // }
        return s.substr(start, end - start + 1);
   /* string longestPalindrome(string s) {

        int len = s.length();

        vector<vector<char> > dict(len, vector<char>(len, 0));
        int maxLen = 0;
        string res = "";
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (isPalindrome(s, i, j, &dict)) {
                    if (maxLen <= (j - i + 1)) {
                        maxLen = j - i + 1;
                        res = s.substr(i, maxLen);
                    }
                }
            }
        }
       if (res == "") {
           res = s[0];
       }
        return res;
    }
private:
    bool isPalindrome(string s, int start, int end, vector<vector<char> > *dictp) {

        if (start >= end) {
            return true;
        }
        bool res;
        if ((*dictp)[start][end] > 0) { //已经查过是回文
            res = true;
        } else if ((*dictp)[start][end] == 0) { //没查过
            if (s[start] == s[end] && isPalindrome(s, start + 1, end - 1, dictp)) { //是回文
                (*dictp)[start][end] = 1;
                res = true;
            } else {
                (*dictp)[start][end] = -1; //不是回文
                res = false;
            }
        } else if ((*dictp)[start][end] == -1) { //已经查过不是回文
            res = false;
        }
        return res;
    } */
};
int main() {
    string s = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";    
    //string s = "aabbc";    
    Solution x;
    string res = x.longestPalindrome(s);    
    cout << res << endl;
}

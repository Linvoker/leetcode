//从头到尾找出以i开头的最长回文串,时间复杂度可能要O(n^3),超时了.所以用这种方法下的动态规划来解决,但动态规划自顶向下时间复杂度为O(n^2),空间复杂度为O(n^2),会在同一个地方出现内存超限错误.
/*class Solution {
public:
    string longestPalindrome(string s) {
       // if (s == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") {
         //   return "";
        //}
        vector<vector<char>> table(s.size(), vector<char>(s.size(), -1));
        int max_size = 0;
        string ret_str;
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j >= i; j--) {
                if (dp(s, table, i, j) == 1) {
                    if (max_size < j - i + 1) {
                        max_size = j - i + 1;
                        ret_str = s.substr(i, j - i + 1);
                    }
                    break;
                }
            }
        }
        return ret_str;
    }
    int dp(string &s, vector<vector<char>> &table, int i, int j) {
        if (i == j) {
            return table[i][j] = 1;
        }
        if (i == j - 1) {
            return s[i] == s[j] ? table[i][j] = 1 : table[i][j] = 0;
        }
        
        if (table[i][j] == 1) {
            return 1;
        } else if (table[i][j] == 0) {
            return 0;
        } else {
            if (dp(s, table, i + 1, j - 1) == 1 && s[i] == s[j]) {
                return table[i][j] = 1;
            } else {
                return table[i][j] = 0;
            }
        }
    }
    
};*/
//动态规划自底向上,奇数偶数分开进行
class Solution {
public:
    string longestPalindrome(string s) {
      
        if (s.size() < 2) {
            return s;
        }
        int max_size = 0;
        string ret_str;
        vector<int> table(s.size(), true);//初始化长度为1的串
        for (int i = 3; i <= s.size(); i += 2) {//i表示奇数串的长度
            for (int j = 0; j <= s.size() - i; j++) {//j为串的起始索引
                if (table[j + 1] == true && s[j] == s[j + i - 1]) {
                    table[j] = true;
                    if (max_size < i) {
                        max_size = i;
                        ret_str = s.substr(j, i);
                    }
                } else {
                    table[j] = false;
                }
            }
        }
        
        for (int i = 0; i < s.size() - 1; i++) {//初始化长度为2的串
            if (s[i] == s[i + 1]) {
                table[i] = true;
                if (max_size < 2) {
                    max_size = 2;
                    ret_str = s.substr(i, 2);
                }
            } else {
                table[i] = false;
            }
        }
        for (int i = 4; i <= s.size(); i += 2) {//i表示偶数串的长度
            for (int j = 0; j <= s.size() - i; j++) {//j为串的起始索引
                if (table[j + 1] == true && s[j] == s[j + i - 1]) {
                    table[j] = true;
                    if (max_size < i) {
                        max_size = i;
                        ret_str = s.substr(j, i);
                    }
                } else {
                    table[j] = false;
                }
            }
        }
        return ret_str;
    }
    
};

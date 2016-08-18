//都没做出来,time limit excceed

//状态转移方程:minCut(0, n) = min{1 + minCut(0, i) + minCut(i, n)}.n为string的总长度,0<i<n.
//DP,时间复杂度为O(n^3),超时了
class Solution {
public:
    int minCut(string s) {
        unordered_map<string, int> table;
        return helper(s, table);
    }
    int helper(string s, unordered_map<string, int> &table){
        if (table.find(s) != table.end()) {
            return table[s];
        }
        
        if (isPalindrome(s, 0, s.size() - 1)) {//不超时的办法就是事先用O(n^2)的时间复杂度找到所有是回文的子字符串,将其存入unordered_map<string,int>里.
            return table[s] = 0;
        }
        
        
        int min_cut = INT_MAX;
        for (int i = 1; i < s.size(); i++) {//从索引1左边开始切开
            min_cut = std::min(min_cut, 1 + helper(s.substr(0, i), table) + helper(s.substr(i), table));
        }
        return table[s] = min_cut;      
    }
    bool isPalindrome(const string &candidates, int begin ,int end) {//这个end是包括在回文内的
        while(begin < end) {
            if (candidates[begin++] != candidates[end--]) {
                return false;
            }
        }
        return true;
    }
};
//状态转移方程:minCut(0, n) = min{1 + minCut(0, i) + minCut(i, n)}.n为string的总长度,0<i<n.
//事先用O(n^2)的时间复杂度找到所有是回文的子字符串,将其存入unordered_map<string,int>里.
//时间复杂度O(n^2)
//还是失败了
/*class Solution {
public:
    int minCut(string s) {
        //if (s == "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") {
        //    return INT_MAX;
        //}
        unordered_map<string, int> table;
        unordered_map<string, bool> table_palindrome;
        for (int i = 0; i < s.size(); i++) {//
            table_palindrome[s.substr(i, 1)] = true;//将所有n^2个字符串排列组合(字符串必须连续)都放入table_palindrome里
            for (int j = i - 1, k = i + 1; j >= 0 && k <= s.size() - 1; j--, k++) {//奇数个数,以i为基础向两遍展开判断是否是回文
                if (s[j] == s[k]) {
                    table_palindrome[s.substr(j, k - j + 1)] = table_palindrome[s.substr(j + 1, k - j - 1)];//s.substr(j + 1, (k - 1) - (j + 1) + 1)
                } else {
                    table_palindrome[s.substr(j, k - j + 1)] = false;
                }
            }
            if (i < s.size() - 1) {
                table_palindrome[s.substr(i, 2)] = s[i] == s[i + 1] ? true : false;
            }
            for (int j = i - 1, k = i + 2; j >= 0 && k <= s.size() - 1; j--, k++) {//偶数个数,以i,i+1为基础向两遍展开判断是否是回文
                if (s[j] == s[k]) {
                    table_palindrome[s.substr(j, k - j + 1)] = table_palindrome[s.substr(j + 1, k - j - 1)];
                } else {
                    table_palindrome[s.substr(j, k - j + 1)] = false;
                }
            }
        }
        return helper(s, table, table_palindrome);
    }
    int helper(string s, unordered_map<string, int> &table, const unordered_map<string, bool> &table_palindrome){
        if (table.find(s) != table.end()) {
            return table[s];
        }
        //不超时的办法就是事先用O(n^2)的时间复杂度找到所有是回文的子字符串,将其存入unordered_map<string,bool>里.
        if (table_palindrome.find(s)->second == true) {
            return table[s] = 0;
        }
        
        
        int min_cut = INT_MAX;
        for (int i = 1; i < s.size(); i++) {//从索引1左边开始切开
            min_cut = std::min(min_cut, 1 + helper(s.substr(0, i), table, table_palindrome) + helper(s.substr(i), table, table_palindrome));
        }
        return table[s] = min_cut;      
    }
};

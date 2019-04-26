#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> um;
        um['*'] = 2;
        um['/'] = 2;
        um['+'] = 1;
        um['-'] = 1;
        int a = 0, b = 0, c = 0, i = 0, j = 0;
        int k = 0;
        for (; s[k] >= '0' && s[k] <= '9' || s[k] == ' '; k++) {
            if (s[k] != ' ') {
                a = a * 10 + (s[k] - '0');
            }
        }
        if (k >= s.length()) {
            return a;
        }
        for (; s[k] == ' '; k++) {} //找到第一个符号
        i = k++;
        if (um.find(s[i]) != um.end()) {
            //todo 报错 非法表达式
        }

        for (; s[k] >= '0' && s[k] <= '9' || s[k] == ' '; k++) {
            if (s[k] != ' ') {
                b = b * 10 + (s[k] - '0');
            }
        }

        while (k < s.length()) {
            for (; s[k] == ' '; k++) {} //找到第二个符号
            j = k++; //第二个符号
            if (um.find(s[j]) != um.end()) {
                //todo 报错 非法表达式
            }

            for (; s[k] >= '0' && s[k] <='9' || s[k] == ' '; k++) {
                if (s[k] != ' ') {
                    c = c * 10 + (s[k] - '0');
                }
            }

            if (um[s[i]] >= um[s[j]]) {
                switch (s[i]) {
                    case '*': a *= b; break;
                    case '/': a /= b; break;
                    case '+': a += b; break;
                    case '-': a -= b; break;
                }
                b = c;
                i = j;
                //j = 0;
            } else {
                switch (s[j]) {
                    case '*': b *= c; break;
                    case '/': b /= c; break;
                    case '+': b += c; break;
                    case '-': b -= c; break;
                }
                //j = 0;
            }
            c = 0;
        }
        int res = 0;
        switch (s[i]) {
            case '*': res = a * b; break;
            case '/': res = a / b; break;
            case '+': res = a + b; break;
            case '-': res = a - b; break;
        }
        return res;
    }
};
int main() {
    cout << (new Solution())->calculate("3+5 / 2") << endl;
    //cout << (new Solution())->calculate("100-1-2-3-4-5-6-7-8-9-10") << endl;
    //cout << (new Solution())->calculate("3+2*2") << endl;
}

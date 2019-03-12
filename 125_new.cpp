#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#include<string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        return helper(s, 0, s.length() - 1);  
    }
    bool helper(string &s, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (!isalnum(s[start])) {
            return helper(s, start+1, end); 
        }
        if (!isalnum(s[end])) {
            return helper(s, start, end-1); 
        }

        if (tolower(s[start]) == tolower(s[end])) {
            return helper(s, start+1, end-1);
        }
    }
};
int main() {
    string s = "race a car";
    cout << (new Solution())->isPalindrome(s) << endl;
}

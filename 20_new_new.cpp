#include<iostream>
#include<vector>
#include<stack>
//#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> dict(1000, 0);
        dict['('] = ')';
        dict['{'] = '}';
        dict['['] = ']';
        
        stack<char> sc;
        for (auto c : s) {
            if (dict[c] != 0) { //左括号
                sc.push(c);      
            } else { //右括号
                if (sc.empty() || dict[sc.top()] != c) {
                    return false;
                } else {
                    sc.pop();
                }
            }
        }
        return sc.empty();
    }
};
int main()
{
    cout << (new Solution)->isValid("{[]}") << endl;
}

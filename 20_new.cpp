#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack{};
        unordered_map<char, char> dict{}; //不用hash 量少可以直接用if else更快
        dict['('] = ')';
        dict['['] = ']';
        dict['{'] = '}';
        for (auto it = s.begin(); it < s.end(); it++) {
            if (*it == '{' || *it == '(' || *it == '[') {
                stack.push(*it); 
            } else {
                if (!stack.empty() && dict[stack.top()] == *it) { //记得判断非空!
                    stack.pop();
                } else {
                    return false;
                }
            }
        }        
        return stack.empty();
    }
};
int main() {
    Solution x;
    //cout << x.isValid("(]") << endl;
    cout << x.isValid("()[]{}") << endl;
}

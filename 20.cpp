//没什么好说的，用栈保存左括弧，用一个hash表来匹配
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m_char {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        stack<char> s_char;
        for (auto c : s) {
            if (c == '{' || c == '[' || c == '(') {
                s_char.push(c);
            } else {
                if (!s_char.empty() && c == m_char[s_char.top()]) {
                    s_char.pop();
                } else {
                    return false;
                }
            }
        }
        return s_char.empty();
    }
};

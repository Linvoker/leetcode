//1.不能出现s中的一个字符对应到t中两个不同的字符

//2.不能出现s中的两个不同字符对应到t中同一个字符
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        typedef unordered_map<char, char> MapType;
        MapType m_char_char_s;
        MapType m_char_char_t;
        
        auto it_s = s.begin();
        auto it_t = t.begin();
        for (; it_s != s.end(); ++it_s, ++it_t) {
            if (m_char_char_s.find(*it_s) == m_char_char_s.end() && 
                m_char_char_t.find(*it_t) == m_char_char_t.end()) {
                m_char_char_s[*it_s] = *it_t; 
                m_char_char_t[*it_t] = *it_s;
            } else if (m_char_char_s[*it_s] == *it_t && m_char_char_t[*it_t] == *it_s) {
                continue;
            } else {
                return false;
            }
        }
        return true;
        
    }
};

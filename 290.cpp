//pattern和str同时遍历，用一个map<char, string>和一个map<string, char> 实现双映射
//pattern和str个数也要相等
//istringstream的用法
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m_char_str;
        unordered_map<string, char> m_str_char;//双映射bijection
        
        string s;//暂存vector里的元素
        vector<string> v_str;
        istringstream veccin(str);
        while (veccin >> s) {
            v_str.push_back(s);
        }
        if (v_str.size() != pattern.size()) {
          //  return false;
        }
        int p_size = pattern.size();
        for (int i = 0; i < p_size; i++) {
            if (m_char_str.find(pattern[i]) == m_char_str.end() && 
                    m_str_char.find(v_str[i]) == m_str_char.end()) {//两个map都找不到对应的值时
                m_char_str[pattern[i]] = v_str[i];
                m_str_char[v_str[i]] = pattern[i];
            } else if (m_char_str[pattern[i]] == v_str[i] && 
                    m_str_char[v_str[i]] == pattern[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
//其他人的（速度一样）
/*class Solution {
    public:
bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (int i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            } else if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
}  ; */ 

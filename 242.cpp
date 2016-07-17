//使用unordered_map,一个记录字符，一个记录出现次数
class Solution {
public:
    bool isAnagram(string s, string t) {
        typedef unordered_map<char, int> Umap;
        Umap m_char_int;
        for (auto &ele : s) {
            if (m_char_int.find(ele) == m_char_int.end()) {
                m_char_int.insert(pair<char, int>(ele, 1));
            } else {
                ++m_char_int[ele];
            }
        }
        for (auto &ele : t) {
            if (m_char_int.find(ele) == m_char_int.end()) {
                return false;
            } else {
                --m_char_int[ele];
            }
        }
        for (auto &ele : m_char_int) {//如果遍历m_char_int的每一个第二个成员都为0，则返回true
            if (ele.second != 0) {
                return false;
            }
        }
        return true;
    }
};
//更高效率解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0; i < n; i++) {//同时加减counts的第二位，只需循环一次
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (auto count : counts)
            if (count.second) return false;
        return true;
    }
};

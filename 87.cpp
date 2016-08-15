//在某位置切开s1，则s1左侧与s2左侧相同数量的子串为Scramble String，并且s1右侧与s2右侧相同数量的子串为Scramble 
//String；或者s1左侧与s2右侧相同数量的子串为Scramble String，并且s1右侧与s2左侧相同数量的子串为Scramble String。
//这题不用DP会快很多
//DP,230ms
/*class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> table;
        return helper(s1, s2, table);
        
    }
    bool helper(string s1, string s2, unordered_map<string, bool> &table) {
        if (s1.size() == 1) {//s2.size() == 1也会因此而成立
            return s1[0] == s2[0];
        }
        
        if (table.find(s1 + s2) != table.end()) {
            return table[s1 + s2];
        }
        for (int i = 1; i < s1.size(); i++) {//在ｉ左边分成两半
            if (helper(s1.substr(0, i), s2.substr(s2.size() - i, i), table) && helper(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i), table) 
                     || helper(s1.substr(0, i), s2.substr(0, i), table) && helper(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i), table)) {
                return table[s1 + s2] = true;             
            }
        }
        return table[s1 + s2] = false;
    }
};*/
//改进版,DP + 剪枝函数,8ms
/*
class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> table;
        return helper(s1, s2, table);
        
    }
    bool helper(string s1, string s2, unordered_map<string, bool> &table) {
        if (s1.size() == 1) {//s2.size() == 1也会因此而成立
            return s1[0] == s2[0];
        }
        
        if (table.find(s1 + s2) != table.end()) {
            return table[s1 + s2];
        }
        
        int count[26] = {0};
        for(int i=0; i<s1.size(); i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return table[s1 + s2] = false;
        }
        for (int i = 1; i < s1.size(); i++) {//在ｉ左边分成两半
            if (helper(s1.substr(0, i), s2.substr(s2.size() - i, i), table) && helper(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i), table) 
                     || helper(s1.substr(0, i), s2.substr(0, i), table) && helper(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i), table)) {
                return table[s1 + s2] = true;             
            }
        }
        return table[s1 + s2] = false;
    }
};*/
//做好的办法:没用DP的剪枝函数.4ms
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return helper(s1, s2);
        
    }
    bool helper(string s1, string s2) {
        if (s1.size() == 1) {//s2.size() == 1也会因此而成立
            return s1[0] == s2[0];
        }
        
        int count[26] = {0};
        for(int i=0; i<s1.size(); i++)//只适用于小写字母
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)//s1里的各个字母的总数应该与s2里的各个字母的总数相等
                return false;
        }
        for (int i = 1; i < s1.size(); i++) {//在ｉ左边分成两半
            if (helper(s1.substr(0, i), s2.substr(s2.size() - i, i)) && helper(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)) 
                     || helper(s1.substr(0, i), s2.substr(0, i)) && helper(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
                return true;             
            }
        }
        return false;
    }
};

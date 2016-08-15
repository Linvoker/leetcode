//insert不一定要插入到尾部,可以任意指定位置插入,delete也是
//replace可以将原有字符替换成任何字符
//http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
//先用递归写出来,超时了
/*class Solution {
public:
    int minDistance(string word1, string word2) {
        
        return helper(word1, word2, word1.size(), word2.size());
    }
    int helper(string &word1, string &word2, int edit_range1, int edit_range2) {//参数是大小
        if (edit_range1 == 0 && edit_range2 == 0) {
            return 0;
        } else if (edit_range1 == 0) {
            return 1 + helper(word1, word2, edit_range1, edit_range2 - 1);//插入
        } else if (edit_range2 == 0) {
            return 1 + helper(word1, word2, edit_range1 - 1, edit_range2);//删除
        } else {
            if (word1[edit_range1 - 1] == word2[edit_range2 - 1]) {
                return helper(word1, word2, edit_range1 - 1, edit_range2 - 1);
            } else {
                int ins = helper(word1, word2, edit_range1, edit_range2 - 1);//插入
                int del = helper(word1, word2, edit_range1 - 1, edit_range2);//删除
                int rep = helper(word1, word2, edit_range1 - 1, edit_range2 - 1);//替换
                return 1 + std::min(ins, std::min(del, rep));
            }
        }
    }
};*/
//动态规划自顶向下
/*class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> table(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return helper(word1, word2, word1.size(), word2.size(), table);
    }
    int helper(string &word1, string &word2, int edit_range1, int edit_range2, vector<vector<int>> &table) {//参数是string的有效长度
        if (table[edit_range1][edit_range2] != -1) {
            return table[edit_range1][edit_range2];
        }
        if (edit_range1 == 0 && edit_range2 == 0) {
            return 0;
        } else if (edit_range1 == 0) {
            return table[edit_range1][edit_range2] = 1 + helper(word1, word2, edit_range1, edit_range2 - 1, table);//插入
        } else if (edit_range2 == 0) {
            return table[edit_range1][edit_range2] = 1 + helper(word1, word2, edit_range1 - 1, edit_range2, table);//删除
        } else {
            if (word1[edit_range1 - 1] == word2[edit_range2 - 1]) {
                return table[edit_range1][edit_range2] = helper(word1, word2, edit_range1 - 1, edit_range2 - 1, table);
            } else {
                int ins = helper(word1, word2, edit_range1, edit_range2 - 1, table);//插入
                int del = helper(word1, word2, edit_range1 - 1, edit_range2, table);//删除
                int rep = helper(word1, word2, edit_range1 - 1, edit_range2 - 1, table);//替换
                return table[edit_range1][edit_range2] = 1 + std::min(ins, std::min(del, rep));
            }
        }
    }
};*/
//动态规划自顶向下简化版
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> table(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return helper(word1, word2, word1.size(), word2.size(), table);
    }
    int helper(string &word1, string &word2, int edit_range1, int edit_range2, vector<vector<int>> &table) {//参数是string的有效长度
        if (table[edit_range1][edit_range2] != -1) {
            return table[edit_range1][edit_range2];
        }
        if (edit_range1 == 0) {//插入操作
            return edit_range2;
        } else if (edit_range2 == 0) {//插入操作
            return edit_range1; 
        } else {
            if (word1[edit_range1 - 1] == word2[edit_range2 - 1]) {
                return table[edit_range1][edit_range2] = helper(word1, word2, edit_range1 - 1, edit_range2 - 1, table);
            } else {
                int ins = helper(word1, word2, edit_range1, edit_range2 - 1, table);//插入
                int del = helper(word1, word2, edit_range1 - 1, edit_range2, table);//删除
                int rep = helper(word1, word2, edit_range1 - 1, edit_range2 - 1, table);//替换
                return table[edit_range1][edit_range2] = 1 + std::min(ins, std::min(del, rep));
            }
        }
    }
};

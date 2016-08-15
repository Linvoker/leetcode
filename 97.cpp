//其实就是一个DFS+table = DP(自顶向下).
//状态转移方程:table[i][j] = table[i - 1][j] || table[i][j - 1],当s1[0] == s2[0] == s3[0]时.
//table[i][j]保存s1长度为i,s2长度为j时是否可以interleaving成长度为i+j的s3
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //本来打算用deque<deque<bool>>可以省空间的,但是只有两个状态,不能用-1来标识是否已打表
        vector<vector<int>> table(s1.size() + 1, vector<int>(s2.size() + 1, -1));//因为table[0][x]和table[s1.size()][x]都要存数
        return helper(s1, s2, s3, table);
    }
    bool helper(string s1, string s2, string s3, vector<vector<int>> &table) {
        int m = s1.size();
        int n = s2.size();
        
        if (table[m][n] != -1) {//已在表中
            return table[m][n];//隐式转换
        }
        if (s1.empty()) {//s1,s2之一为空时只需返回另一个是否等于s3即可
            return table[m][n] = s2 == s3;
        } 
        if (s2.empty()) {//s1,s2之一为空时只需返回另一个是否等于s3即可
            return table[m][n] = s1 == s3;
        }
        
        if (s1[0] == s3[0] && s2[0] == s3[0]) {
            bool temp;
            if ((temp = helper(s1.substr(1), s2, s3.substr(1), table)) == true) {
                return table[m][n] = temp; 
            } else {
                return table[m][n] = helper(s1, s2.substr(1), s3.substr(1), table); 
            }    
                
        } else if (s1[0] == s3[0]) {
            return table[m][n] = helper(s1.substr(1), s2, s3.substr(1), table);
        } else if (s2[0] == s3[0]){//
            return table[m][n] = helper(s1, s2.substr(1), s3.substr(1), table); 
        } else {
            return table[m][n] = false;
        }
    }
};
//BFS也可以解决但会比DFS+table的DP慢
//失败了= =
/*class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        queue<pair<string, string>> q_str;
        q_str.push(make_pair(s1, s2));
        int count = 1;
        bool mark = false;
        while (!q_str.empty()) {
            if (q_str.front().first == "") {
                if (q_str.front().second == s3) {
                    mark = true;
                } 
            } else if (q_str.front().second == "") {
                if (q_str.front().first == s3) {
                    mark = true;
                }
            } else {
                if (q_str.front().first[0] == s3[0] && q_str.front().second[0] == s3[0]) {
                    q_str.push(make_pair(q_str.front().first.substr(1), q_str.front().second));
                    q_str.push(make_pair(q_str.front().first, q_str.front().second.substr(1)));
                    mark = true;
                } else if (q_str.front().first[0] == s3[0]) {
                    q_str.push(make_pair(q_str.front().first.substr(1), q_str.front().second));
                    mark = true;
                } else if (q_str.front().second[0] == s3[0]) {
                    q_str.push(make_pair(q_str.front().first, q_str.front().second.substr(1)));
                    mark = true;
                } else {
                    ;
                }
            }
            if (!s3.empty()) {
                s3 = s3.substr(1);
            }
            q_str.pop();
            if (--count == 0) {
                if (mark == true) {
                    count = q_str.size();//重置当前层的队列成员计数器
                    mark = false;
                } else {
                    return false;
                }
                
            }
        }
        return true;
    }

};

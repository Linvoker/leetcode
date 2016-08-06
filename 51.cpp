//16ms思路1：
//建立一个candidates用于查询candidates[i]对应第i个位置上为Q的string
//
/*class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> trace;
        vector<vector<string>> ret_vec;
        
        string temp(n, '.');
        vector<string> candidates(n, temp);
        int i = 0;
        while (i < n) {
            candidates[i][i] = 'Q';
            i++;
        }
        
        backTracking(trace, ret_vec, candidates, INT_MIN , n);
        return ret_vec;
    }
    void backTracking(vector<string> &trace, vector<vector<string>> &ret_vec, vector<string> &candidates, int danger, const int n) {
        if (trace.size() == n) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = 0; i <= candidates.size() - 1; i++) {
            if (candidates[i] == "") {//剪枝函数
                continue;
            }
            bool mark = 0;
            for (int y1 = 0; y1 < trace.size(); y1++) {//计算之前每一行'Q'的坐标与当前要插入'Q'的坐标的斜率。O(n^2)的最坏时间复杂度
                int x1 = trace[y1].find('Q');
                int x2 = i;
                int y2 = trace.size();
                if (abs(x1 - x2) == abs(y1 - y2)) {
                    mark = 1;
                    break;
                }
            }
            if (mark == 1) {//剪枝函数
                continue;
            }
            
            trace.push_back(candidates[i]);
            
            vector<string> temp = candidates;//不能再原candidates上做改动，因为backTracing()递归返回来时i++要继续使用当前candidates
            temp[i] = "";
            backTracking(trace, ret_vec, temp, i, n);
            
            trace.pop_back();
        }
        return;
    }
};*/
//思路1的变形（不见得更好）：用一个vector<int>trace_int来同步记录trace，方便查找对角线冲突16ms
/*class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> trace;
        vector<vector<string>> ret_vec;
        vector<int> trace_int;
        
        string temp(n, '.');
        vector<string> candidates(n, temp);
        int i = 0;
        while (i < n) {
            candidates[i][i] = 'Q';
            i++;
        }

        backTracking(trace, trace_int, ret_vec, candidates, INT_MIN , n);
        return ret_vec;
    }
    void backTracking(vector<string> &trace, vector<int> &trace_int, vector<vector<string>> &ret_vec, vector<string> &candidates, int danger, const int n) {
        if (trace.size() == n) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = 0; i <= candidates.size() - 1; i++) {
            if (candidates[i] == "") {
                continue;
            }
            bool mark = 0;
            for (int y1 = 0; y1 < trace_int.size(); y1++) {//O(n)的最坏时间复杂度
                int x1 = trace_int[y1];
                int x2 = i;
                int y2 = trace_int.size();
                if (abs(x1 - x2) == abs(y1 - y2)) {
                    mark = 1;
                    break;
                }
            }
            if (mark == 1) {
                continue;
            }
            
            trace.push_back(candidates[i]);
            trace_int.push_back(i);
            
            vector<string> temp = candidates;
            temp[i] = "";
            backTracking(trace, trace_int, ret_vec, temp, i, n);
            
            trace.pop_back();
            trace_int.pop_back();
        }
        return;
    }
};*/
//思路2：8ms标准做法，思路是看来的，自己写的
//将trace初始化为n*n的'.'矩阵，直在再trace上添删'Q'，每次在一行里添'Q'前先调用isValid()确定是否对角线和直线上有没有其他‘Q’。最后push_back()

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret_vec;
        
        string temp(n, '.');
        vector<string> trace(n, temp);//将trace初始化为n*n的'.'矩阵，到达终止条件直接可以push_back()
        
        backTracking(trace, ret_vec , 0, n);
        return ret_vec;
    }
    //传递行的索引row_index和n是为了调用isValid()要用
    void backTracking(vector<string> &trace, vector<vector<string>> &ret_vec, int row_index, const int n) {
        if (row_index == n) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = 0; i <= n - 1; i++) {
            
            if (!isValid(trace, i, row_index, n)) {//剪枝函数
                continue;
            }
            
            trace[row_index][i] = 'Q';
            
            backTracking(trace, ret_vec, row_index + 1, n);
            
            trace[row_index][i] = '.';
        }
        return;
    }
    bool isValid(vector<string> &trace, int i, int row_index, int n) {
            for (int j = i, k = row_index; k > 0; ) {//直线O(n)的最坏时间复杂度
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            for (int j = i, k = row_index; j > 0 && k > 0; ) {//对角线之一O(n)的最坏时间复杂度
                j--;
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            for (int j = i, k = row_index; j < n - 1 && k > 0; ) {//对角线之一O(n)的最坏时间复杂度
                j++;
                k--;
                if(trace[k][j] == 'Q') {
                    return false;
                }
            }
            return true;
    }
};

//这题看似和46. Permutations相近，其实46题不要求输出顺序，而这题要有顺序。
//这题如果单纯的backtrace而不做任何改进，会出现time limited excceed

//这是我用数学方法做的，0ms，可以改进的是n-1的阶乘可以用vector<int>保存直接调用，不用再计算了，因为n<=9,已经固定了

//最高位在candidates中的位置（索引）为index = (k - 1) / ((n - 1)!);将candidates[index]push_back()进ret_str，接着删掉candidates中index的值，
//避免影响下一位的取值；接着递归调用k = (k - 1) % ((n - 1)!) + 1, n = n - 1,递归执行直到n == 0.
class Solution {
public:
    string getPermutation(int n, int k) {
        string ret_str;
        string candidates;
        int i = 1;
        while (i <= n) {
            candidates.push_back('0' + i);
            i++;
        }
        
        helper(ret_str, n, k, candidates);
        return ret_str;
    }
    void helper(string &ret_str, int n, int k, string &candidates) {
        if (n == 0) {
            return;
        }
        int x = 1;//保存(n-1)的阶乘
        int i = 1;
        while (i <= n - 1) {//计算n-1的阶乘
            x *= i;
            i++;
        }
        
        int index = (k - 1) / x;
        ret_str.push_back(candidates[index]);//放入
        candidates.erase(candidates.begin() + index);//删除candidates里的此元素
        helper(ret_str, n - 1, (k - 1) % x + 1, candidates);
        return;
    }
    
};
//超时了
/*class Solution {
public:
    string getPermutation(int n, int k) {
        string trace;
        string candidates;
        string ret_str;
        int i = 1;
        int x = n;
        while (x--) {
            candidates.push_back('0' + i++);
        }
        bool mark = 0;
        backTracing(candidates, ret_str, trace, k, mark, n);
        return ret_str;
    }
    void backTracing(string candidates, string &ret_str, string &trace, int &k, bool &mark, const int n) {
        if (mark) {//终止所有递归
            return;
        }    
        if (trace.size() == n) {
            if (!(--k)) {
                ret_str = trace;
                mark = !mark;
            }
            return;
        }
        
        for (int i = 0; i <= candidates.size() - 1; i++) {
            //没有剪枝函数，所有都要遍历，但k减完之后递归完全退出
            trace.push_back(candidates[i]);
            
            string temp = candidates;
            temp.erase(temp.begin() + i);
            backTracing(temp, ret_str, trace, k, mark, n);
            
            trace.pop_back();
            
        }
    }
};

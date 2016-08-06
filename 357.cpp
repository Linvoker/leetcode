//不要可以去想用backtracking
//以下backtraking的办法花了1000+ms，把基本所有情况都便利了一遍，找出了所有的非独一无二数字，但这不是题目的要求，题目要求找到独一无二的数字的数量
/*class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> trace;
        int sum = 0;
        int begin = 1;
        int i = n;
        while (i >= 2) {
            backTracking(sum, trace, i, begin);
        
            i--;
        }
        return pow(10, n) - sum;
    }
    void backTracking(int &sum, vector<int> &trace, int bit, int begin) {
        if (bit == 0) {
            return;
        }
        for (int i = begin; i <= 9; i++) {
            if (std::find(trace.begin(), trace.end(), i) != trace.end()) {
                sum += pow(10, bit - 1);
                continue;
            }
            trace.push_back(i);
            backTracking(sum, trace, bit - 1, 0);
            trace.pop_back();
            
        }
    }
};*/
//https://discuss.leetcode.com/topic/48332/java-o-1-with-explanation
//countNumbersWithUniqueDigits(n) = countNumbersWithUniqueDigits(n - 1) + 9 * (9 * 8 * 7..) 括弧内有n-1个乘数
//0ms
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int sum = 1;
        int i = 1;
        while (i <= n) {
            sum += 9 * factorial(9, i - 1);
            i++;
        }
        return sum;
    }
    int factorial(int num, int count) {//阶乘
        if (count == 0) {
            return 1;
        } else {
            return num * factorial(num - 1, --count);
        }
    }
    
};

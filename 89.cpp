//其实格雷码有公式，谷歌以下就有
//但是我之前不知道，就用tag里的backtracking写了一个较为复杂的，但是应该可以理解
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret_vec;
        int trace = 0;
        const vector<char> candidates{0, 1};//其实也可以另保存一个{1, 0}就更好理解了
        backTracking(ret_vec, trace, candidates, 0, n - 1);
        return ret_vec;
    }
    void backTracking(vector<int> &ret_vec, int &trace, const vector<char> &candidates, int begin, int bit) {
        if (bit < 0) {//终止函数
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin, count = 0; count < 2; count++, i = (i + 1) % 2) {//循环两次一定退出return
            //没有剪枝函数
            trace += candidates[i] == 0 ? 0 : pow(2, bit);
            bit--;
            
            if (count == 0) {
                backTracking(ret_vec, trace, candidates, 0, bit);//一层里第一次循环进入的递归的candidates一定是{1， 0}
            } else {
                backTracking(ret_vec, trace, candidates, 1, bit);//一层里第二次循环进入的递归的candidates一定是{0， 1}
            }
            bit++;
            trace -= candidates[i] == 0 ? 0 : pow(2, bit);
            
        }
    }
};

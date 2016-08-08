//失败了,time limit excceeded,因为一些返回空vector的极端test case.那些例子如果合法,打印出来还是会time limit exceeded.
//学完动态规划再来做吧
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret_vec;
        string trace;
        /*for (int i = 0; i < s.size(); i++) {//看看能不能直接返回空vector,但失败了,这是另一个题目139.word break,用动态规划解决,我现在还不会
            if (i != 0 && s[i] == s[i - 1]) {
                continue;
            } else {
                auto it = wordDict.begin();
                for (; it != wordDict.end(); ++it) {
                    if (find((*it).begin(), (*it).end(), s[i]) != (*it).end()) {
                        break;
                    }
                }
                if (it == wordDict.end()) {
                    return ret_vec;
                }
            }
        }*/
    
        backTracking(ret_vec, s, trace, wordDict, 0);
        return ret_vec;
        
    }
    void backTracking(vector<string> &ret_vec, const string &candidates, string &trace, unordered_set<string> &wordDict, int begin) {
        if (begin == candidates.size()) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            
            string temp;
            for (int k = begin; k <= i; k++) {
                temp.push_back(candidates[k]);
            }
            if (wordDict.find(temp) == wordDict.end()) {//剪枝函数
                continue;
            } else {
                trace += temp;
                if (i < candidates.size() - 1) {
                    trace.push_back(' ');
                }
                
                backTracking(ret_vec, candidates, trace, wordDict, i + 1);
                
                if (i < candidates.size() - 1) {
                    trace.pop_back();
                }
                //trace -= temp;
                for (int k = begin; k <= i; k++) {
                    trace.pop_back();
                }   
                
            }
        }
    }
};

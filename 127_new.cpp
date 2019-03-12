#include<vector>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<climits>

using namespace std;
class Solution {
public:

    //这题应该使用bfs(广度优先搜索)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 0;
        queue<string> qu;
        unordered_set<string> us(wordList.begin(), wordList.end()); //记录还未搜索过的元素
        qu.push(beginWord);
        while(!qu.empty()) {
            step++;
            int q_size = qu.size();
            for (int i = 0; i < q_size; i++) {
                //bfs当前queue
                string curWord = qu.front();
                qu.pop();
                //测试用例的缘故 直接逐个替换字符比hasOneDiff更快
                for (unsigned int j = 0; j < curWord.length(); j++) { //找出能一步变成的字符串
                    char tmp = curWord[j];
                    for (int k = 0; k < 26; k++) {
                        curWord[j] = 'a' + k;
                        if (us.find(curWord) != us.end()) {
                            qu.push(curWord);
                            us.erase(curWord);
                            if (curWord == endWord) {
                                return step + 1;
                            }
                        }
                    }
                    curWord[j] = tmp;//恢复curWord的第j位字符
                }
            }
        }
        return 0;
    }
    /*bfs(广度优先搜索) 下一个节点指向vector里的内容，而不是随机修改字符
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = 0;
        queue<string> qu;
        unordered_set<string> us; //记录已经搜索过的元素
        qu.push(beginWord);
        while(!qu.empty()) {
            step++;
            int q_size = qu.size();
            for (int i = 0; i < q_size; i++) {
                //bfs当前queue
                string curWord = qu.front();
                qu.pop();
                //hasOneDiff()方式，
                for (auto word : wordList) {
                    if (us.find(word) == us.end() && hasOneDiff(curWord, word)) {
                        qu.push(word);
                        us.insert(word);
                        if (word == endWord) {
                            return step + 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    bool hasOneDiff(string x, string y) {
        int diff_cnt = 0;
        if (x.length() != y.length()) {
            return false;
        }
        for (unsigned int i = 0; i < x.length(); i++) {
            if (x[i] != y[i]) {
                diff_cnt++;
            }
        }
        return diff_cnt == 1;
    }*/

    /* 回溯法 会超时(相当于dfs)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int step = INT_MAX; //记录最短步数
        unordered_set<string> us;
        for (auto word : wordList) {
            us.insert(word);
        }
        backtrack(beginWord, endWord, wordList, us, &step, 1);
        return step == INT_MAX ? 0 : step;
    }
    void backtrack(string curWord, string endWord,  vector<string>& wordList, unordered_set<string>& us, int *step, int curStep) {
        if (curWord == endWord) { //终止条件
            *step = min(curStep, *step);
            return;
        }
        for (auto word : wordList) {
            if (us.find(word) != us.end()) { //存在于set里，还没用过
                if (!hasOneDiff(curWord, word)) { // 剪枝函数
                    continue;
                }

                us.erase(word);
                backtrack(word, endWord, wordList, us, step, curStep + 1);
                us.insert(word);
            }
        }
        return;
    }
    bool hasOneDiff(string x, string y) {
        int diff_cnt = 0;
        if (x.length() != y.length()) {
            return false;
        }
        for (unsigned int i = 0; i < x.length(); i++) {
            if (x[i] != y[i]) {
                diff_cnt++;
            }
        }
        return diff_cnt == 1;
    }*/
};
int main () {
    string start = "qa";
    string end = "sq";
    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    cout << (new Solution())->ladderLength(start, end, wordList) << endl;
}

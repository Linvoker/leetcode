#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>

using namespace std;
typedef struct Node {
    Node *link[26] = {};
    int val = 0;
} Node;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new Node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto curNode = root;
        for (auto it = word.begin(); it != word.end(); it++) {
            if (curNode->link[*it - 'a'] != NULL) { //已存在该节点
                curNode = curNode->link[*it - 'a'];
            } else { //节点不存在
                curNode = curNode->link[*it - 'a'] = new Node;
            }
        }
        curNode->val = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto curNode = root;
        for (auto it = word.begin(); it != word.end(); it++) {
            if (curNode->link[*it - 'a'] != nullptr) { //已存在该节点
                curNode = curNode->link[*it - 'a'];
            } else { //节点不存在
                return false;
            }
        }
        //搜索完就简单隐藏掉，为了此题做的特殊处理。
        if (curNode->val == 1) {
            curNode->val = 0;
            return true;
        } else {
            return false;
        }
        //return curNode->val == 1 ? true : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto curNode = root;
        for (auto it = prefix.begin(); it != prefix.end(); it++) {
            if (curNode->link[*it - 'a'] != nullptr) { //已存在该节点
                curNode = curNode->link[*it - 'a'];
            } else { //节点不存在
                return false;
            }
        }
        return true;
    }
private:
    Node *root;
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto trie = new Trie;
        for (auto word: words) {
            trie->insert(word);
        }
        vector<string> res;
        string word = "";
        for (unsigned int i = 0; i < board.size(); i++) {
            for (unsigned int j = 0; j < board[i].size(); j++) {
                backTracking(board, i, j, trie, res, word);
            }
        }
        return res;
    }
    void backTracking(vector<vector<char>>& board, int i, int j, Trie *trie, vector<string> &res, string &word){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == 0) { //越界或已经走过
            return;
        }

        word += board[i][j];

        if (!trie->startsWith(word)) { //剪枝函数
            word.pop_back();
            return;
        }
        if (trie->search(word)) { //终止条件 但是不能停
            //trie->delete(word);
            res.push_back(word);
        }
        
        char tmp =  board[i][j];
        board[i][j] = 0;
        backTracking(board, i - 1, j, trie, res, word);
        backTracking(board, i + 1, j, trie, res, word);
        backTracking(board, i, j - 1, trie, res, word);
        backTracking(board, i, j + 1, trie, res, word);
        board[i][j] = tmp; //返回false的时候需要还原board
        word.pop_back();
    }
};
int main () {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    (new Solution)->findWords(board, words);
}

#include <string>
#include <iostream>
using namespace std;
typedef struct Node {
    Node *link[26];
    int val;
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
            if (it + 1 == word.end()) { //最后一个char
                curNode->val = 1;
                break;
            }
            if (curNode->link[*it - 'a'] != nullptr) { //已存在该节点
                curNode = curNode->link[*it - 'a'];
            } else { //节点不存在
                curNode = curNode->link[*it - 'a'] = new Node;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto curNode = root;
        for (auto it = word.begin(); it != word.end(); it++) {
            if (it + 1 == word.end()) { //最后一个char
                return curNode->val == 1 ? true : false;
            }
            if (curNode->link[*it - 'a'] != nullptr) { //已存在该节点
                curNode = curNode->link[*it - 'a'];
            } else { //节点不存在
                return false;
            }
        }
        return false;
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
int main() {
    Trie* obj = new Trie();
    string word = "apple";
    obj->insert(word);
    cout << obj->search(word) << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;
    //cout << obj->startsWith(prefix) << endl;
}

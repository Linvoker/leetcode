//208. Implement Trie (Prefix Tree)是这题的基础.此题加入了'.'这种模式,所以搜索函数会变成回溯形式而与208不一样
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : is_end(false), next(26, nullptr) {
        
    }
    bool is_end;//不能是private,否则要写一个接口函数调用和更改它们,否则Trie里不能访问
    vector<TrieNode *> next;
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *move = root;
        for (int i = 0; i < word.size(); i++) {
            if (move->next[word[i] - 'a'] == nullptr) {
                move->next[word[i] - 'a'] = new TrieNode;
            }
            move = move->next[word[i] - 'a'];
        }
        
        if (!move->is_end) {
            move->is_end = true;
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word, root);
    }

private:
    TrieNode* root;
    
    bool searchHelper(string word, TrieNode *root) {//回溯
        if (root == nullptr || word.empty() && !root->is_end) {//终止函数
            return false;
        }
        if (word.empty() && root->is_end) {//终止函数
            return true;
        }
        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {//出现'.'时无剪枝函数
                if (searchHelper(word.substr(1), root->next[i])) {
                    return true;
                }
            }
            return false;
        } else {//也无剪枝函数
            return searchHelper(word.substr(1), root->next[word[0] - 'a']);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

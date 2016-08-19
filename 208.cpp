class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : is_end(false), next(26, nullptr) {
        
    }

    bool is_end;//不能是private,否则要写一个接口函数调用和更改它们,否则Trie里不能访问
    vector<TrieNode *> next;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {//search()和startWith()有重复语句,可以写一个find()函数中和
        TrieNode *move = root;
        for (int i = 0; i < word.size(); i++) {
            if (move->next[word[i] - 'a'] == nullptr) {
                return false;
            } else {
                move = move->next[word[i] - 'a'];
            }
        }
        return move->is_end;//要看是否为end.
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *move = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (move->next[prefix[i] - 'a'] == nullptr) {
                return false;
            } else {
                move = move->next[prefix[i] - 'a'];
            }
        }
        return true;//最后一个结点不为空则这条路径至少包含prefix的整个字符
    }

private:
    TrieNode* root;
};

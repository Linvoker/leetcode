//时间复杂度为O(n*m)
/*class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto c : ransomNote) {
            auto it = magazine.find(c);
            if (it == magazine.npos) {
                return false;
            } else {
                magazine[it] = '0';
            }
        }
        return true;
    }
};*/
//时间复杂度为O(n+m)
//直接用vector<char>比hash表更快,因为只有26个元素,直接用vector就好
struct func {
    public:
        std::size_t operator()(const char &c) const {
        return c - 'a';
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int, func> umap;
        for (auto c : magazine) {
            ++umap[c];
        }
        for (auto c : ransomNote) {
            if (umap.find(c) == umap.end() || umap[c] == 0) {
                return false;
            } else {
                --umap[c];
            }
        }
        return true;
    }
};

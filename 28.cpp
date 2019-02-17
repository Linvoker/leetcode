class Solution {
public:
    //暴力O(N^2)，标准答案应该使用kmp算法
    /* int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int haystacksize = haystack.size();
        int needlesize = needle.size();
        for (int i = 0; i < haystacksize; i++) {
            int j = 0;
            for (; j < needlesize; j++) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
            if (j == needlesize) {
                return i;
            }
        }
        return -1;
    } */
    //kmp
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        vector<int> next;
        kmpPrefix(needle, next);

        int j = 0;//已匹配的个数(pattern的索引)
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next[j - 1];//注意这里
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
}
    void kmpPrefix(string &pattern, vector<int> &next) {
        next.push_back(0);
        int j = 0;
        for (int i = 1; i < pattern.size(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j - 1];//注意这里
            }
            if (pattern[j] == pattern[i]) {
                j++;
            }
            next.push_back(j);
        }
    }
    
};

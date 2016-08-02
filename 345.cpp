//别用unordered_set,很愚蠢,慢的离谱，元素这么少直接写出来就好了
class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ) {
            
            if (!isvowel(s[i])) {
                i++;
                continue;
            }
            if (!isvowel(s[j])) {
                j--;
                continue;
            }
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    bool isvowel(char c) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            return true;
        }
        else return false;
    }
};


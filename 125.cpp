//我没用<cctype>这个库函数，自己手写的很费劲

/*class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {//会有偶数最后i可能会大于j
            if (s[i] < 'a' && s[i] > 'Z' || s[i] < 'A' && s[i] > '9' || s[i] > 'z' || s[i] < '0') {
                i++;
                continue;
            }
            if (s[j] < 'a' && s[j] > 'Z' || s[j] < 'A' && s[j] > '9' || s[j] > 'z' || s[j] < '0') {
                j--;
                continue;
            }
            
            if (s[i] < '9' && s[i] > '0' || s[j] < '9' && s[j] > '0') {//单独处理两端可能是数字的情况，是为了单独处理字母时方便
                if (s[i] == s[j]) {
                    i++;
                    j--;
                    continue;
                } else {
                    return false;
                }
            }
            if ((s[i] < 'a' ? s[i] + 'a' - 'A' : s[i]) != (s[j] < 'a' ? s[j] + 'a' - 'A' : s[j])) {//处理字母
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};*/
//isalnum()判断是否是（大小写）字母或者数字
//tolower(),toupper()，如果不能转换，那么字符会保持原状，所以不用可以区分字母和数字
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int i = 0;
        int j = s.size() -1;
        while (i < j) {
            if (!isalnum(s[i])){
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
        
            if (tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};

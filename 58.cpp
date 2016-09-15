//先从尾到首找到第一个非空格字符,再从这个非空格字符起从尾到首找到第一个空格并计数.
//思路是对的,但这样写太复杂
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int j = -1;
        for (int i = s.size() - 1; i >= 0; i--) {//先从尾到首找到第一个非空格字符
            if (s[i] == ' ') {
                continue;
            } else {
                j = i;
                break;
            }
        }
        
        
        for (int i = j; i >= 0; i--) {//首找到第一个空格并计数.
            if (s[i] != ' ') {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};

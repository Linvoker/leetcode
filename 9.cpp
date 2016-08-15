//这题和7. Reverse Integer相近,不过只翻转了后一半的数字
//https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) {//一定要有后面那个,否则21120会返回true的
            return false;
        }
        if (x >= 0 && x <= 9) {
            return true;
        }
        int ret_val = 0;
        int fast = x;
        int slow = x;
        while (fast != 0) {
            ret_val = ret_val * 10 + slow % 10;
            slow /= 10;
            fast /= 100;
        }
        return slow == ret_val || slow == ret_val / 10;
    }
    
};

//思路1：和实现sqrt()思路一样
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long)mid * mid < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low * low == num;
    }
};
//思路2（别人的，不适用于实现sqrt()）：根据平方数的性质，所有的平方数都为1+3+5+7+9+11...的和
/*class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

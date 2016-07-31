// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

/*class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                return mid;//一定会到达这里，因为这个数一定是存在的
            }
        }
        return -1;//永远也到不了这里
    }
};*/
//简化版
class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (low <= high) {//找到>=target的第一个数
            int mid = low + (high - low) / 2;
            if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};


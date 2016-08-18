//只是加一而已,不用考虑太多
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + 1 != 10) {//退出循环,没必要进位了
                digits[i] = digits[i] + 1;
                break;
            } else {//digits[i] == 10,才会继续循环
                digits[i] = 0;
            }
        }
        if (digits[0] == 0) {//第一位的进位
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

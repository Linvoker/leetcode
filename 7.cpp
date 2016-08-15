//转换为string投机取巧
/*class Solution {
public:
    int reverse(int x) {
        string temp = std::to_string(abs(x));
        std::reverse(temp.begin(), temp.end());
        int ret_val;
        try {
            ret_val = std::stoi(temp);
        } catch (std::out_of_range) {
            return 0;
        }
        return ret_val * (x >= 0 ? 1 : -1);
    }
};*/
//正规做法
//http://www.geeksforgeeks.org/write-a-c-program-to-reverse-digits-of-a-number/
class Solution {
public:
    int reverse(int x) {
        long long ret_val = 0;
        while (x != 0) {//这么做恰好可以不用考虑正负号问题
            ret_val = ret_val * 10 + x % 10;
            x = x / 10;
        }
        return (ret_val > INT_MAX || ret_val < INT_MIN) ? 0 : static_cast<int> (ret_val);
    }
};

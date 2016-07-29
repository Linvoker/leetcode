//两个指针方法O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //if (nums.empty()) {
        //    return 0;
       // }
        auto first_ptr = nums.begin();
        auto second_ptr = nums.begin();
        int count = INT_MAX;
        int temp;
        while (first_ptr != nums.end()) {//每次大循环first右移一位，temp加上这位的值
            temp += *first_ptr;
            while (temp >= s) {
                count = count < first_ptr - second_ptr + 1 ? count : first_ptr - second_ptr + 1;
                if (first_ptr == second_ptr) {
                    break;
                }    
                temp -= *second_ptr;
                ++second_ptr;
            }
            ++first_ptr;
        }
        
        return count == INT_MAX ? 0 : count;
    }
};


class Solution {
public:
    //常规做法，一个一个计数 时间复杂度O(n)
    /*int hammingWeight(uint32_t n) {
        int cnt = 0;
        do {
            if (n & 1) {
                cnt++;
            }
        } while(n >>= 1);
        return cnt;
    }*/
    //n = n & (n - 1) 会扣除一个最右边的1，所以时间复杂度是O(m)，m是1的数量
    //110 & 101 = 100
    //101 & 100 = 100
    //100 & 011 = 000
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }
};

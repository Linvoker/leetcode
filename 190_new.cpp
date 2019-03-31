#include<vector>
#include<iostream>
#include<queue>
//#include<unordered_set>
#include<climits>
#include<bitset>
using namespace std;
class Solution {
public:
    /*uint32_t reverseBits(uint32_t n) {
        return reverseHelper(n, 31);
    }
    uint32_t reverseHelper(uint32_t n, int pos) {
        if (pos == 0) {
            return n & 1;
        }
        bool curBit = n & (1 << pos);
        uint32_t res = reverseHelper(n, pos - 1);
        res = (res << 1) + (int)curBit;
        return res;
    }*/
    uint32_t reverseBits(uint32_t n) {
        bool curBit;
        uint32_t res; //res记录交换之后的局部值
        for (int i = 0; i < 32; i++) {
            curBit = n & (1 << i); //第i位的bool值
            res = (res << 1) + (int)curBit;
        }
        return res;
    }
};
int main() {
    cout << (new Solution)->reverseBits(43261596) << endl;
}

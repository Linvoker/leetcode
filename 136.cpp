//空间复杂度为O(n)的办法
/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m_int_int;
        for (auto v : nums) {
            if (m_int_int[v] == 1) {
                m_int_int.erase(v);
            } else {
                ++m_int_int[v];
            }
                
        }
        return m_int_int.begin()->first;//m_int_int里剩下的那个就是它
    }
};*/
//异或满足结合律,相同两数异或为0，数与0异或还是数，最终会剩下那个单独的数
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto v : nums) {
            ret ^= v;
        }
        return ret;
    }
};

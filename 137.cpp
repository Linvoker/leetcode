//这个用了O(n)的空间复杂度,和Single Number那题用的一样
/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m_int_int;
        for (auto v : nums) {
            if (m_int_int[v] == 2) {
                m_int_int.erase(v);
            } else {
                ++m_int_int[v];
            }
        }
        return m_int_int.begin()->first;
    }
};*/


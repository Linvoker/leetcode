//用map记录出现次数
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m_int_int;
        for (auto v : nums1) {
            ++m_int_int[v];
        }
        vector<int> ret_vec;
        for (auto v : nums2) {
            if (m_int_int[v] > 0) {//要m_int_int里v的值大于1才将v加入ret_vec
                ret_vec.push_back(v);
                --m_int_int[v];
            }
        }
        return ret_vec;
    }
};

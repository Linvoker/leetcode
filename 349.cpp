//求两个集合的交集，没有顺序
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s_int;
        for (auto v : nums1) {
            if (s_int.find(v) == s_int.end()) {
                s_int.insert(v);
            }
        }
        vector<int> ret_vec;
        for (auto v : nums2) {
            if (s_int.find(v) != s_int.end() && 
                    find(ret_vec.begin(), ret_vec.end(), v) == ret_vec.end()) {//不仅要s_int里有v，而且要ret_vec里不存在v才将v加入ret_vec
                ret_vec.push_back(v);
            }
           //if (s_int.erase(v)) {
            //   ret_vec.push_back(v);
           //}
        }
        return ret_vec;
    }
};

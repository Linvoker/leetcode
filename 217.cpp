//用散列表构成的unorder_set来解决此问题
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        typedef unordered_set<int> Uset;
        if (nums.empty() == 1 || nums.size() == 1) {
            return false;
        }
        Uset u_set;
        for (auto ele : nums) {
            if (u_set.find(ele) == u_set.end()) {
                u_set.insert(ele);
            } else {
                return true;
            }
        }
        return false;
    }
};

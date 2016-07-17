//使用c++stl散列表unordered_map来存储元素和索引，
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        typedef unordered_map<int, int> Umap;
        if (nums.empty() == 1 || nums.size() == 1) {
            return false;
        }
        Umap m_int_int;
        int i = 0;//索引
        for (auto ele : nums) {
            if (m_int_int.find(ele) == m_int_int.end()) {//散列表里没有就存入
                m_int_int.insert(pair<int, int> (ele, i));
            } else if (i - m_int_int.find(ele)->second <= k) {//散列表里有了就比较索引大小
                return true;
            } else { //距离太远就删掉这个已保存的之前的pair<int, int>(ele, i),重新保存一份当前pair
                m_int_int.erase(ele);
                m_int_int.insert(pair<int, int> (ele, i));
            }
            i++;
        }
        return false;
    }
};

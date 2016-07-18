//使map按值排序（利用vector<pair<int,int>>）
//sort只能用于顺序容器(vector)，不能用于关联容器(map)的排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m_int_int;
        for (auto &v : nums) {
            ++m_int_int[v];
        }
        vector<pair<int, int>> v_pair;
        for (auto &m : m_int_int) {//将顺序容器转换为关联容器，用以排序
            v_pair.push_back(m);
        }
        sort(v_pair.begin(), v_pair.end(), compare);//按照pair的第二个数从大到小排列m_int_int
        
        
        vector<int> ret_vec;
        int i = 0;
        for (auto it = v_pair.begin(); i < k && it != v_pair.end(); ++it, ++i) {
            ret_vec.push_back(it->first);
        }
        return ret_vec;
    }
    static bool compare(pair<int, int> &x, pair<int, int> &y) {
        return x.second > y.second;
    }
};

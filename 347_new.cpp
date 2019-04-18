class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (auto num : nums) {
            um[num]++;
        }
        vector<pair<int, int>> vp;
        for (auto it = um.begin(); it != um.end(); it++) {
            vp.push_back(*it);
        }
        make_heap(vp.begin(), vp.end(), comp);
        vector<int> res;
        
        for (int i = 0; i < k; i++) {
            res.push_back(vp[0].first); //取出大顶堆的顶
            pop_heap(vp.begin(), vp.end(), comp);
            vp.pop_back();
        }
        return res;
        
    }
    static bool comp(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

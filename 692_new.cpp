#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for (auto word : words) { //先hash存次数
            um[word]++;
        }
        vector<pair<string, int>> vp;
        for (auto it = um.begin(); it != um.end(); it++) { //pair入vector，以便make_heap
            vp.push_back(*it);
        }

        make_heap(vp.begin(), vp.begin() + k, comp); //维护一个大小为k的小顶堆
        for (auto it = vp.begin() + k; it != vp.end(); it++) {
            if (it->second > vp[0].second || 
                 (it->second == vp[0].second && it->first < vp[0].first)) { //大于堆的最小值则入堆
                pop_heap(vp.begin(), vp.begin() + k, comp);
                swap(vp[k - 1], *it); //将新值换到可以push的位置
                push_heap(vp.begin(), vp.begin() + k, comp); 
            } 
        }
        vector<string> res;
        for (int i = 0; i < k; i++) { //从小到大取出
            res.insert(res.begin(), vp[0].first);
            pop_heap(vp.begin(), vp.begin() + k - i, comp); //缩小范围pop
        }
        return res;
    }
    static bool comp(pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
    /* vector<int> topKFrequent(vector<int>& nums, int k) {
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
    } */
};
int main() {
    //vector<string> vs = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> vs = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    (new Solution)->topKFrequent(vs ,4);
    return 0;

}

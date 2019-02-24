class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        unordered_map<string, multiset<string>> umap;
        for (auto &str : strs) {
            string temp = str;
            std::sort(str.begin(), str.end());
            umap[str].insert(temp);
        }
        
        vector<vector<string>> ret_vec;
        for (auto &ele : umap) {
            vector<string> trace;
            for (auto &str : ele.second) {
                trace.push_back(str);
            }
            ret_vec.push_back(trace);
        }
        return ret_vec;
    }
};
//同类字符串如果不考虑字符出现的次数，则下面我的思路也是对的
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int, vector<string>> resMap;
        for (unsigned int i = 0; i < strs.size(); i++) {
            int score = 0;
            for (auto c : strs[i]) {
                score |= 1 << (c - 'a'); //左移出一个唯一的整数作为key放入unordered_map
            }
            resMap[score].push_back(strs[i]);
        }
        vector<vector<string>> res{};
        for (auto it = resMap.begin(); it != resMap.end(); it++) {
            res.push_back((*it).second);
        }
        return res;
    }
};


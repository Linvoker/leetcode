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

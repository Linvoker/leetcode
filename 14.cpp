//不能按照常规思路来想,
//找最长相同前缀应该不管cashe的空间局限性,strs的每个元素的各个位置逐一比较即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret_str;
        int max_size = 0;
        for (auto &str : strs) {
            max_size = std::max(max_size, static_cast<int> (str.size()));
        }
        for (int j = 0; j < max_size; j++) {
            char comp = strs[0][j];
            int i = 1;
            for (; i < strs.size(); i++) {
                if (strs[i][j] != comp) {
                    break;
                }
            }
            if (i == strs.size()) {//循环彻底走完,每次都相等
                ret_str.push_back(comp);
            } else {
                break;
            }
        }
        return ret_str;
    }
};

//这题必须先排序了

//其他人的办法，思路和我的差不多，但是更快用红黑树map存储num代替vector，便于erase()元素
//28ms
/*class Solution {
public:
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int>> v;
    vector<int> r;
    map<int, int> map;
    for (int i : num)
    {
        if (map.find(i) == map.end()) map[i] = 0;
        map[i]++;
    }
    permuteUnique(v, r, map, num.size());
    return v;
}

void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
{
    if (n <= 0)
    {
        v.push_back(r);
        return;
    }
    for (auto &p : map)
    {
        if (p.second <= 0) continue;
        p.second--;
        r.push_back(p.first);
        permuteUnique(v, r, map, n - 1);
        r.pop_back();
        p.second++;
    }
}
};*/
//40ms
//我的办法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ret_vec;
        vector<int> trace;
        backTracing(ret_vec, trace, nums);
        return ret_vec;
    }
    void backTracing(vector<vector<int>> &ret_vec, vector<int> &trace, vector<int> candidates) {
        if (candidates.empty()) {
            ret_vec.push_back(trace);
            return;
        }
        for (int i = 0; i <= candidates.size() - 1; i++) {
            if (i != 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            trace.push_back(candidates[i]);
            
            vector<int> temp = candidates;
            temp.erase(temp.begin() + i);//直接擦除有点耗时间，执行一次耗时T(size() - 1 - i);
            //std::swap(temp[i], temp[temp.size() - 1]);//这个办法不可行，会打乱下一个递归的candidates[]的顺序，使得同一个trace可能出现两遍
            //temp.pop_back();
            backTracing(ret_vec, trace, temp);
            
            trace.pop_back();
        }
    }
};

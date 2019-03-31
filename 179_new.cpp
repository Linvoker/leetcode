class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> vs; //用来排序
        for (auto num : nums) {
            vs.push_back(to_string(num));
        }
        sort(vs.begin(), vs.end(), comp);
        for (auto str : vs) {
            res.append(str);
        }
        
        //特殊case，移除前导0
        int i = 0, size = res.size();
        for (; i < size; i++) {
            if (res[i] != '0' || i == size - 1) {
                break;
            }
        }
        return res.substr(i);
        
    }
    static bool comp(string a, string b) {
        return a + b > b + a; //这是一个trick，按照拼接字符串的结果大小排序
    }
};

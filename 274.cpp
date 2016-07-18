//https://zh.wikipedia.org/wiki/H%E6%8C%87%E6%95%B0
//用先排序
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() == 1) {
            return 0;
        }
        sort(citations.begin(), citations.end(), compare);//第三个参数是函数指针
        int citations_size = citations.size();
        int i = 0;
        for (; i + 1 <= citations[i] && i < citations_size; ++i) {}
        return i;
    }
//private:
    static bool compare(int x, int y) {//比较函数一定要是静态成员函数或者全局函数
        return x > y;
    }
};

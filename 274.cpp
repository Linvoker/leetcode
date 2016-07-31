//https://zh.wikipedia.org/wiki/H%E6%8C%87%E6%95%B0
//用先排序O(nlgn)
/*class Solution {
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
};*/
//建立一个vector（hashtable），数组下标i,值为val,意思是引用次数=i的文章数为val篇。
//unordered_map更慢，因为它的查找要用哈希函数，虽然和vector一样都是O(n),但实际花费时间更多，推荐使用vector，但vector要注意一定要初始化
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int max_cite_times = 0;//先找到最大引用次数
        /*for (auto vi : citations) {
            if (vi > max_cite_times) {
                max_cite_times = vi;
            }
        }*/
        //vector<int> v_int(max_cite_times + 1, 0);//初始化这个hash表
        unordered_map<int, int> m_int;
        for (auto vi : citations) {//建立这个hashtable
            //++v_int[vi]; 
            ++m_int[vi];
            if (vi > max_cite_times) {
                max_cite_times = vi;
            }
        }
        //int count = v_int[max_cite_times];
        int count = m_int[max_cite_times];
        
        int i = max_cite_times;
        for ( ; i > count; i--) {
            //count += v_int[i - 1];
            count += m_int[i - 1];
        }
        return i;
    }
};

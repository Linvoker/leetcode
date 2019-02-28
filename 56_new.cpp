#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    //时间复杂度O(nlgn)
    static bool compair(Interval l1, Interval l2) {
        return l1.start < l2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return vector<Interval>{};
        }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), compair);//先根据start排序

        auto cur_start = intervals[0].start;
        auto cur_end = intervals[0].end;
        struct Interval tmp; //用tmp记录需要加入res的成员
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (cur_end < it->start) { //这里是个间隙，需要一次res.push_back
                tmp.start = cur_start;
                tmp.end = cur_end;
                res.push_back(tmp);

                cur_start = it->start;
                cur_end = it->end;
            } else { //有重叠的时候更新cur_end
                cur_end = max(cur_end, it->end);
            }
        }
        //退出循环之后还有一次res.push_back
        tmp.start = cur_start;
        tmp.end = cur_end;
        res.push_back(tmp);

        return res;
    }
};
int main() {
    struct Interval tmp1(1,3);
    struct Interval tmp2(2,6);
    struct Interval tmp3(8,13);
    struct Interval tmp4(15,18);
    //[[1,4],[0,4]]
    //struct Interval tmp1(1,4);
    //struct Interval tmp2(0,0);
    //vector<Interval> intervals{tmp1, tmp2};
    vector<Interval> intervals{tmp1, tmp2, tmp3, tmp4};
    auto ret = (new Solution)->merge(intervals);
    return 0;
}

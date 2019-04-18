#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K - 1, points.end(), comp); //从小到大
        points.resize(K);
        //return vector<vector<int>> (points.begin(), points.begin() + K);
        return points;
     }
     static bool comp(vector<int> &v1, vector<int> &v2) {
        return (v1[0]*v1[0] + v1[1]*v1[1]) < (v2[0]*v2[0] + v2[1]*v2[1]);
     }
    /* vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //unordered_map<int, vector<vector<int>>> um;// 距离=>list
        unordered_map<int, vector<int>> um;// 距离=>list
        vector<int> vi;
        for (auto pair : points) {
            int p = pow(pair[0], 2) + pow(pair[1], 2);
            if (um.find(p) == um.end()) {
                //um[p].push_back(pair);
                um[p] = pair;
                vi.push_back(p);
            }
        }
        //nth_element(vi.begin(), vi.end() - K, vi.end()); //从大到小
        nth_element(vi.begin(), vi.begin() + K - 1, vi.end()); //从大到小
        vector<vector<int>> res;
        for (auto it = vi.begin(); it != vi.begin() + K; it++) {
            res.push_back(um[*it]);
        }
        return res;
    } */
};

int main() {
    vector<vector<int>> points {{0,1},{1,0}};
    int K = 2;
    //vector<vector<int>> points {{1,3},{-2,2}};
    //vector<vector<int>> points {vector<int> {3,3},vector<int>{5,-1},vector<int>{-2,4}};
    //vector<vector<int>> points {vector<int> {3,3},vector<int>{5,-1},vector<int>{-2,4}};
    //int K = 2;
    (new Solution)->kClosest(points, K);
}

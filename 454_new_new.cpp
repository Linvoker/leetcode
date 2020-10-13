#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    unordered_map<int, int> um;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                um[A[i] + B[j]] += 1; 
            }
        }
        int res = 0;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                if (um.find(-C[i] - D[j]) != um.end()) {
                    res += um[-C[i] - D[j]]; 
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> A = {1, 2};
    vector<int> B = {-2,-1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << (new Solution)->fourSumCount(A,B,C,D) << endl;
}

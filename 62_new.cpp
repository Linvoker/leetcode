#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        vector<vector<int>> table(m, vector<int>(n, -1));
        return dp(m - 1, n - 1, table);
    }
    int dp(int i, int j, vector<vector<int>> &table) {
        if (i == 0 || j == 0) {
            return 1;
        }
        if (table[i][j] != -1) {
            return table[i][j];
        }
        return table[i][j] = dp(i - 1, j, table) + dp(i, j - 1, table);
    }
};
int main() {
    cout << (new Solution)->uniquePaths(3, 2) << endl;
}

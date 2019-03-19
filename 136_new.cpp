#include<vector>
#include<iostream>
#include<stack>
//#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num; 
        }
        return res;
    }
};
int main () {
    //vector<int> gas{1,2,3,4,5};
    //vector<int> cost{3,4,5,1,2};
    vector<int> gas{1,2,2, 3,3,1,5};
    cout << (new Solution)->singleNumber(gas) <<endl;
}


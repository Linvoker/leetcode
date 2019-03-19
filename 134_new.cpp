#include<vector>
#include<iostream>
#include<stack>
//#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g_size = gas.size();
        for (int i = 0; i < g_size; i++) {
            int cur = i, remain = 0;
            int j = 0;
            for (; j < g_size; j++) {
                if ((remain = remain + gas[cur] - cost[cur]) < 0)  {
                    break ;
                } 
                cur = (cur + 1) % g_size;
            }
            if (j == g_size) {
                return i;
            }
        }
        return -1;
    }
};
int main () {
    //vector<int> gas{1,2,3,4,5};
    //vector<int> cost{3,4,5,1,2};
    vector<int> gas{2,3,4};
    vector<int> cost{3,4,3};
    cout << (new Solution)->canCompleteCircuit(gas, cost) <<endl;
}


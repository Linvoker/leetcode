#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <climits>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto num : nums) {
            if (us.find(num) == us.end()) {
                us.insert(num); 
            } else {
                return true;
            }
        }
        return false;
    }
};

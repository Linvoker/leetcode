#include<algorithm>
#include<string>
#include<vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> table(3, 0);        
        int i = 0;
        int size = nums.size();
        while(i < size - table[2]) {
            if (nums[i] == 0) {
                if (i == table[0]) {
                    i++;
                    table[0]++;
                    continue;
                }
                swap(nums[table[0]], nums[i]);
                table[0]++;
            } else if (nums[i] == 2) {
                if (i == size - table[2] - 1) {
                    i++;
                    table[2]++;
                    continue;
                }
                swap(nums[size - table[2] - 1], nums[i]);
                table[2]++;
            } else {
                i++;
            }
        }
    }
};
int main() {
    vector<int> nums{0};
    (new Solution)->sortColors(nums);
}

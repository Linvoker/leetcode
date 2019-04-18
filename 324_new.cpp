#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<unordered_set>
#include<climits>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        make_heap(nums.begin(), nums.end());
        int size = nums.size();

        int i = 0, j = floor((size - 1) / 2);
        if (size % 2) {
            
        }
        
    }
};
int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5};
    (new Solution)->findKthLargest(nums, 3);
}

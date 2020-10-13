#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //当前需要替换的位置i
        //下一个值的第一个位置j
        int i = 0;
        for (int j = 0; j < nums.size(); i++) {
            nums[i] = nums[j]; 
            //找下一个j
            do {
                j++;    
            } while (j < nums.size() && nums[j] == nums[j-1]);
        }
        return i;
    }
};
int main() {
    vector<int> shit{0};
    //vector<int> shit{0,0,1,1,1,2,2,3,3,4};
    cout << (new Solution)->removeDuplicates(shit) << endl;
}

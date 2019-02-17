#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
        //这种比下面的靠谱一点
        int removeDuplicates(vector<int>& nums) {
            int p = 0;
            for (auto num : nums) {
                if (num > nums[p]) {
                    nums[++p] = num;
                }
            }
            return p + 1;
        }
        /* int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return size;
        }
        int pos = -1;
        //找到初始需要交换的元素的前一个位置
        for (int i = 0; i < size; i++) {
            if (nums[i] == nums[i+1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            return size;
        }

        for (int i = pos + 1; i < size; i++) {
            if (nums[i] > nums[pos]) {
                //swap(nums[i], nums[pos+1]);
                nums[pos+1] = nums[i];
                pos++;
            }
        }
        return pos + 1;
    } */
};
int main () {
    Solution x;
    vector<int> shit {1,2};
    //vector<int> shit {1,2,2,3,4,4,4,4,5,6,6};
    cout << x.removeDuplicates(shit) << endl;
    for (unsigned int i = 0; i < shit.size(); i++) {
        cout << shit[i] << endl;
    }

}

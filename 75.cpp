//根据follow up，那就不用计数排序吧。
//但我没想到怎么做,我特妹的根本想不出来
//到现在逻辑我还是屡不清
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;//指向可以与0交换的位置
        int j = nums.size() - 1;//指向可以与2交换的位置
        int move = i;
        while (move <= j) {
            if (nums[move] == 1) {
                move++;
            } else if (nums[move] == 0) {
                swap(nums[move], nums[i]);//交换之后nums[i]==0
                i++;
                move++;//与0交换的有可能是0，所以要直接move++
            } else {
                swap(nums[move], nums[j]);
                j--;
            }
            
        }
        return;
    }
};

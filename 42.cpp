//很典型的two pointer问题

//错误复杂的办法
/*class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int water_area = 0;
        int i = 0;
        while (i < height.size() - 1) {
            int left_index = i;
            int right_index = i + 1;
            while (right_index != height.size() - 1 && height[left_index] > height[right_index]) {
                right_index++;
            }
            if (height[left_index] > height[right_index]) {
                left_index = 
            }
            
            int water_level = height[left_index];//求水位线时右边有可能到达数组尾部
            left_index++;
            while (left_index < right_index) {//计算此范围的面积
                water_area += water_level - height[left_index] > 0 ? water_level - height[left_index] : 0;
                left_index++;
            }
            i = right_index;
        }
        return water_area;
    }
};*/
//别人的思路：从左右同时遍历，每次移动都找到左边的临时最高点和右边的临时最高点，如果左边最高点小于右边最高点，那么移动到的位置上一定可以和左边最高点
//的高度之间形成一个块有水的地方,接着继续移动左边的指针。
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int water_area = 0;
        int left_height = 0;
        int right_height = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            left_height = max(left_height, height[i]);
            right_height = max(right_height, height[j]);
            if (left_height <= right_height) {
                water_area += left_height - height[i];
                i++;
            } else {
                water_area += right_height - height[j];
                j--;
            }
        }
        return water_area;
    }
};

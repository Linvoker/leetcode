#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<climits>

using namespace std;
class Solution {
public:
    //先遍历一遍nums看看每个元素有几个邻居(用hash看)
    //vector<int> nums{100, 4, 200, 1, 3, 2};
    //100=>0
    //4=>1 //有几个邻居
    //200=>0
    //1=>1
    //3=>2
    //2=>2
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {return 0;}
        unordered_map<int, int> um;
        for (auto num : nums) {
            um[num] = 0;
            if (um.find(num+1) != um.end()) { //um里有
                um[num+1]++;
                um[num]++;
            }
            if (um.find(num-1) != um.end()) {
                um[num-1]++;
                um[num]++;
            }
        } 
        int longest = 1; //非空nums至少连续长度为1
        for (auto num : nums) {
            if (um[num] == 0) { //没有邻居或者已经遍历过了
                continue;
            } 
            int step = 0;
            //至少有1个邻居
            int i = num;
            while (um[--i] >= 1) { //左邻居遍历
                step++; 
                um[i] = 0;
            } 
            i = num; 
            while (um[++i] >= 1) { //右邻居遍历
                step++; 
                um[i] = 0;
            }
            longest = max(longest, ++step);
        }
        return longest;
    }
};
int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2, 106, 105,103,101,102, 104};
    cout << (new Solution)->longestConsecutive(nums) << endl;
}

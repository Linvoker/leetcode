//不能先将所有vector元素放入m_int_int里，因为有可能有相同元素，这个是错的
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m_int_int;
        int i = 0;
        for (auto v : nums) {
            m_int_int.insert(pair<int, int>(v, i));
            i++;
        }
        int v_size = nums.size();
        for (int j = 0; j < v_size; j++) {
            int temp = m_int_int.find(target - nums[j]);
            if (temp != m_int_int.end()) {
                return vector<int> {j < temp->first}
            }
        }
};*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for (int i = 0; ; i++) {
            auto p = map.find(target-nums[i]);
            if (p!=map.end()) {
                return {i, p->second};//顺序无所谓的
            }
            map[nums[i]]=i;//最后才插入map
        }
    }
};

//https://leetcode.com/problems/two-sum/
//先放入hash
func twoSum(nums []int, target int) []int {
    numDict := map[int]int{}
    for idx, num := range nums {
        numDict[num] = idx
    }
    
    var res []int
    for idx1, num := range nums {
        
        if idx2, ok := numDict[target - num]; ok && idx1 != idx2{
            res = []int{idx1, idx2}
            break;
        }
    }
    return res
}
//一遍遍历一遍放入hash
func twoSum(nums []int, target int) []int {
    numDict := map[int]int{}
    var res []int
    for idx2, num := range nums {
        if idx1, ok := numDict[target - num]; ok {
            res = []int{idx1, idx2}
            break;
        } else {
            numDict[num] = idx2
        }
    }
    return res
}

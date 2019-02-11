//https://leetcode.com/problems/4sum-ii/
//先算前两个数组之和的所有可能性，并放入hash；计算后两个数组之和的所有相反数，若
//hash中存在，则说明4个数组和为0
func fourSumCount(A []int, B []int, C []int, D []int) int {
    sumAB := map[int]int{} //key=>val: sum=>cnt
    for _, valA := range A {
        for _, valB := range B{
            sumAB[valA + valB] += 1
        }
    }
    
    var totalCnt int = 0;
    for _, valC := range C {
        for _, valD := range D {
            if cnt, ok := sumAB[-valC - valD]; ok {
                totalCnt += cnt
            }
        }
    }
    return totalCnt
}

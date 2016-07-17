void forwardMove(int *nums, int numSize, int index) {
    for (int i = index; i < numSize - 1; ++i)
        nums[i] = nums[i + 1];
}


int removeElement(int* nums, int numSize, int val) {
    for (int i = 0; i < numSize; i++) {
        if (nums[i] == val) {
            forwardMove(nums, numSize, i);
            --numSize;
            --i;
        }
    }
    return numSize;
}

int countPairs(int* nums, int numsSize, int k) {
    int res = 0;  // number of pairs meeting the requirements
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if ((i * j) % k == 0 && nums[i] == nums[j]) {
                ++res;
            }
        }
    }
    return res;
}

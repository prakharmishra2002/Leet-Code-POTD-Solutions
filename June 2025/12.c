int maxAdjacentDistance(int* nums, int numsSize) {
    int res = abs(nums[0] - nums[numsSize - 1]);
    for (int i = 0; i < numsSize - 1; ++i) {
        res = fmax(res, abs(nums[i] - nums[i + 1]));
    }
    return res;
}

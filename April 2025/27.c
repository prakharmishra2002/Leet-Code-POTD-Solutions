int countSubarrays(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 1; i < numsSize - 1; ++i) {
        if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
            ++ans;
        }
    }
    return ans;
}

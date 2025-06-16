#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumDifference(int* nums, int numsSize) {
    int ans = -1, premin = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > premin) {
            ans = MAX(ans, nums[i] - premin);
        } else {
            premin = nums[i];
        }
    }
    return ans;
}

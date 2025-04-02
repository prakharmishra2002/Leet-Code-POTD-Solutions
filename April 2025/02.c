long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                long long value = (long long)(nums[i] - nums[j]) * nums[k];
                if (value > res) {
                    res = value;
                }
            }
        }
    }
    return res;
}

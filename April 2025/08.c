bool checkUnique(int* nums, int numsSize, int start) {
    int seen[128] = {0};
    for (int i = start; i < numsSize; i++) {
        if (seen[nums[i]]) {
            return false;
        }
        seen[nums[i]] = true;
    }
    return true;
}

int minimumOperations(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i += 3, ans++) {
        if (checkUnique(nums, numsSize, i)) {
            return ans;
        }
    }
    return ans;
}

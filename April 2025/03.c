long long maximumTripletValue(int* nums, int numsSize) {
    long long res = 0, imax = 0, dmax = 0;
    for (int k = 0; k < numsSize; k++) {
        res = fmax(res, dmax * nums[k]);
        dmax = fmax(dmax, imax - nums[k]);
        imax = fmax(imax, nums[k]);
    }
    return res;
}

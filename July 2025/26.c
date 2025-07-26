long long maxSubarrays(int n, int** conflictingPairs, int conflictingPairsSize,
                       int* conflictingPairsColSize) {
    int* bMin1 = (int*)malloc((n + 1) * sizeof(int));
    int* bMin2 = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) bMin1[i] = bMin2[i] = INT_MAX;
    for (int i = 0; i < conflictingPairsSize; i++) {
        int a = fmin(conflictingPairs[i][0], conflictingPairs[i][1]);
        int b = fmax(conflictingPairs[i][0], conflictingPairs[i][1]);
        if (bMin1[a] > b) {
            bMin2[a] = bMin1[a];
            bMin1[a] = b;
        } else if (bMin2[a] > b) {
            bMin2[a] = b;
        }
    }
    long long res = 0;
    int ib1 = n, b2 = INT_MAX;
    long long* delCount = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = n; i >= 1; i--) {
        if (bMin1[ib1] > bMin1[i]) {
            b2 = fmin(b2, bMin1[ib1]);
            ib1 = i;
        } else {
            b2 = fmin(b2, bMin1[i]);
        }
        res += fmin(bMin1[ib1], n + 1) - i;
        delCount[ib1] +=
            fmin(fmin(b2, bMin2[ib1]), n + 1) - fmin(bMin1[ib1], n + 1);
    }
    long long max = 0;
    for (int i = 0; i <= n; i++) {
        if (delCount[i] > max) max = delCount[i];
    }
    free(bMin1);
    free(bMin2);
    free(delCount);
    return res + max;
}

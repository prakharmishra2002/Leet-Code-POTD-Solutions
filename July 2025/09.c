int maxFreeTime(int eventTime, int k, int* startTime, int startSize,
                int* endTime, int endSize) {
    int n = startSize;
    int res = 0;
    int* sum = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + endTime[i] - startTime[i];
    }
    for (int i = k - 1; i < n; i++) {
        int right = (i == n - 1) ? eventTime : startTime[i + 1];
        int left = (i == k - 1) ? 0 : endTime[i - k];
        int val = right - left - (sum[i + 1] - sum[i - k + 1]);
        res = fmax(res, val);
    }
    free(sum);
    return res;
}

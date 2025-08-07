int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int ans = 0;
    int n = fruitsSize;
    for (int i = 0; i < n; ++i) ans += fruits[i][i];

    int dp() {
        int* prev = malloc(sizeof(int) * n);
        int* curr = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) prev[i] = INT_MIN;
        prev[n - 1] = fruits[0][n - 1];

        for (int i = 1; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) curr[j] = INT_MIN;
            for (int j = (n - 1 - i > i + 1 ? n - 1 - i : i + 1); j < n; ++j) {
                int best = prev[j];
                if (j - 1 >= 0) {
                    best = best > prev[j - 1] ? best : prev[j - 1];
                }
                if (j + 1 < n) {
                    best = best > prev[j + 1] ? best : prev[j + 1];
                }
                curr[j] = best + fruits[i][j];
            }
            int* tmp = prev;
            prev = curr;
            curr = tmp;
        }

        int result = prev[n - 1];
        free(prev);
        free(curr);
        return result;
    }

    ans += dp();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int temp = fruits[j][i];
            fruits[j][i] = fruits[i][j];
            fruits[i][j] = temp;
        }
    }

    ans += dp();
    return ans;
}

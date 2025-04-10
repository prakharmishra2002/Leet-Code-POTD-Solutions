long long dfs(int i, bool limit_low, bool limit_high, const char* low,
              const char* high, int limit, const char* s, int pre_len,
              long long* memo, int n) {
    // recursive boundary
    if (i == n) {
        return 1;
    }
    if (!limit_low && !limit_high && memo[i] != -1) {
        return memo[i];
    }

    int lo = limit_low ? low[i] - '0' : 0;
    int hi = limit_high ? high[i] - '0' : 9;
    long long res = 0;
    if (i < pre_len) {
        for (int digit = lo; digit <= fmin(hi, limit); digit++) {
            res += dfs(i + 1, limit_low && digit == (low[i] - '0'),
                       limit_high && digit == (high[i] - '0'), low, high, limit,
                       s, pre_len, memo, n);
        }
    } else {
        int x = s[i - pre_len] - '0';
        if (lo <= x && x <= fmin(hi, limit)) {
            res = dfs(i + 1, limit_low && x == (low[i] - '0'),
                      limit_high && x == (high[i] - '0'), low, high, limit, s,
                      pre_len, memo, n);
        }
    }
    if (!limit_low && !limit_high) {
        memo[i] = res;
    }
    return res;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit,
                              char* s) {
    char low[32], high[32];
    sprintf(low, "%lld", start);
    sprintf(high, "%lld", finish);
    int n = strlen(high);
    char* padded_low = (char*)malloc(n + 1);

    memset(padded_low, '0', sizeof(char) * n);
    sprintf(padded_low + n - strlen(low), "%s", low);  // align digits
    int pre_len = n - strlen(s);                       // prefix length
    long long* memo = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }
    long long result =
        dfs(0, true, true, padded_low, high, limit, s, pre_len, memo, n);
    free(padded_low);
    free(memo);

    return result;
}

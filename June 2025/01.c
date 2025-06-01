long long distributeCandies(int n, int limit) {
    long long ans = 0;
    for (int i = 0; i <= fmin(limit, n); i++) {
        if (n - i > 2 * limit) {
            continue;
        }
        ans += fmin(n - i, limit) - fmax(0, n - i - limit) + 1;
    }
    return ans;
}

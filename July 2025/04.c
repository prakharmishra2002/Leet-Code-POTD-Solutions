char kthCharacter(long long k, int* operations, int operationsSize) {
    int ans = 0;
    int t;
    while (k != 1) {
        t = 63 - __builtin_clzll(k);
        if ((1LL << t) == k) {
            t--;
        }
        k = k - (1LL << t);
        if (operations[t]) {
            ans++;
        }
    }
    return 'a' + (ans % 26);
}

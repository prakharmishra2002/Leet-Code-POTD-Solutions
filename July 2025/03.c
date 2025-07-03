char kthCharacter(int k) {
    int ans = 0;
    int t;
    while (k != 1) {
        t = 31 - __builtin_clz(k);
        if ((1 << t) == k) {
            t--;
        }
        k = k - (1 << t);
        ans++;
    }
    return 'a' + ans;
}

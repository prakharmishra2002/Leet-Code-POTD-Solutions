const int MOD = 1000000007;
const int MX = 100000;

long long fact[100000];
long long inv_fact[100000];

long long qpow(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init() {
    if (fact[0]) {
        return;
    }
    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
}

long long comb(int n, int m) {
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
}

int countGoodArrays(int n, int m, int k) {
    init();
    return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
}

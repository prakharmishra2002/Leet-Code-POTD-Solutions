const int MOD = 1e9 + 7;
#define MAX_N 10010
#define MAX_P 15  // There are up to 15 prime factors

int c[MAX_N + MAX_P][MAX_P + 1];
int sieve[MAX_N];                    // Minimum prime factor
int ps[MAX_N][MAX_P], psLen[MAX_N];  // List of prime factor counts

void init() {
    if (c[0][0]) {
        return;
    }
    for (int i = 2; i < MAX_N; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                if (sieve[j] == 0) {
                    sieve[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < MAX_N; i++) {
        int x = i;
        while (x > 1) {
            int p = sieve[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            ps[i][psLen[i]++] = cnt;
        }
    }

    c[0][0] = 1;
    for (int i = 1; i < MAX_N + MAX_P; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= MAX_P && j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int idealArrays(int n, int maxValue) {
    init();
    long long ans = 0;
    for (int x = 1; x <= maxValue; x++) {
        long long mul = 1;
        for (int i = 0; i < psLen[x]; i++) {
            mul = mul * c[n + ps[x][i] - 1][ps[x][i]] % MOD;
        }
        ans = (ans + mul) % MOD;
    }
    return ans;
}

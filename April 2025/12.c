typedef struct {
    char *key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, const char *key) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, const char *key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = strdup(key);
    HASH_ADD_STR(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr->key);
        free(curr);
    }
}

int compare(const void *a, const void *b) { return (*(char *)a - *(char *)b); }

long long countGoodIntegers(int n, int k) {
    HashItem *dict = NULL;
    int base = (int)pow(10, (n - 1) / 2);
    int skip = n & 1;
    /* Enumerate the number of palindrome numbers of n digits */
    for (int i = base; i < base * 10; i++) {
        char s[16];
        sprintf(s, "%d", i);
        int len = strlen(s);
        for (int j = len - 1 - skip; j >= 0; j--) {
            s[len + (len - skip - 1 - j)] = s[j];
        }
        s[2 * len - skip] = '\0';
        long long palindromicInteger = atoll(s);
        /* If the current palindrome number is a k-palindromic integer */
        if (palindromicInteger % k == 0) {
            qsort(s, strlen(s), sizeof(char), compare);
            hashAddItem(&dict, s);
        }
    }

    long long *factorial = malloc((n + 1) * sizeof(long long));
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    long long ans = 0;
    for (HashItem *pEntry = dict; pEntry; pEntry = pEntry->hh.next) {
        int cnt[10] = {0};
        for (int j = 0; pEntry->key[j] != '\0'; j++) {
            cnt[pEntry->key[j] - '0']++;
        }
        /* Calculate permutations and combinations */
        long long tot = (n - cnt[0]) * factorial[n - 1];
        for (int j = 0; j < 10; j++) {
            tot /= factorial[cnt[j]];
        }
        ans += tot;
    }

    free(factorial);
    hashFree(&dict);
    return ans;
}

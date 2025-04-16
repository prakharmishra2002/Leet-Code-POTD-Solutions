typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

long long countGood(int *nums, int numsSize, int k) {
    int n = numsSize;
    int same = 0, right = -1;
    HashItem *cnt = NULL;
    long long ans = 0;
    for (int left = 0; left < n; ++left) {
        while (same < k && right + 1 < n) {
            ++right;
            same += hashGetItem(&cnt, nums[right], 0);
            hashSetItem(&cnt, nums[right],
                        hashGetItem(&cnt, nums[right], 0) + 1);
        }
        if (same >= k) {
            ans += n - right;
        }
        hashSetItem(&cnt, nums[left], hashGetItem(&cnt, nums[left], 0) - 1);
        same -= hashGetItem(&cnt, nums[left], 0);
    }
    hashFree(&cnt);
    return ans;
}

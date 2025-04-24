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

void hashEraseItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    HASH_DEL(*obj, pEntry);
    free(pEntry);
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int countCompleteSubarrays(int *nums, int numsSize) {
    int res = 0;
    HashItem *cnt = NULL;
    int n = numsSize;
    int right = 0;
    HashItem *distinct = NULL;
    for (int i = 0; i < numsSize; i++) {
        hashAddItem(&distinct, nums[i], 1);
    }
    int distinct_count = HASH_COUNT(distinct);

    for (int left = 0; left < n; left++) {
        if (left > 0) {
            int remove = nums[left - 1];
            hashSetItem(&cnt, remove, hashGetItem(&cnt, remove, 0) - 1);
            if (hashGetItem(&cnt, remove, 0) == 0) {
                hashEraseItem(&cnt, remove);
            }
        }
        while (right < n && HASH_COUNT(cnt) < distinct_count) {
            int add = nums[right];
            hashSetItem(&cnt, add, hashGetItem(&cnt, add, 0) + 1);
            right++;
        }
        if (HASH_COUNT(cnt) == distinct_count) {
            res += (n - right + 1);
        }
    }
    hashFree(&cnt);
    return res;
}

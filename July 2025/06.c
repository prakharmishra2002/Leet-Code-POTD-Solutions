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

typedef struct {
    int *nums1, *nums2;
    int nums1Size, nums2Size;
    HashItem *cnt;
} FindSumPairs;

FindSumPairs *findSumPairsCreate(int *nums1, int nums1Size, int *nums2,
                                 int nums2Size) {
    FindSumPairs *obj = (FindSumPairs *)malloc(sizeof(FindSumPairs));
    obj->nums1 = nums1;
    obj->nums1Size = nums1Size;
    obj->nums2 = nums2;
    obj->nums2Size = nums2Size;
    obj->cnt = NULL;
    for (int i = 0; i < nums2Size; i++) {
        hashSetItem(&obj->cnt, nums2[i],
                    hashGetItem(&obj->cnt, nums2[i], 0) + 1);
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs *obj, int index, int val) {
    hashSetItem(&obj->cnt, obj->nums2[index],
                hashGetItem(&obj->cnt, obj->nums2[index], 0) - 1);
    obj->nums2[index] += val;
    hashSetItem(&obj->cnt, obj->nums2[index],
                hashGetItem(&obj->cnt, obj->nums2[index], 0) + 1);
}

int findSumPairsCount(FindSumPairs *obj, int tot) {
    int ans = 0;
    for (int i = 0; i < obj->nums1Size; i++) {
        int rest = tot - obj->nums1[i];
        if (hashFindItem(&obj->cnt, rest)) {
            ans += hashGetItem(&obj->cnt, rest, 0);
        }
    }
    return ans;
}

void findSumPairsFree(FindSumPairs *obj) {
    hashFree(&obj->cnt);
    free(obj);
}

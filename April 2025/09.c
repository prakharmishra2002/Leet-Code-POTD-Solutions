typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *)malloc(sizeof(HashItem));
    pEntry->key = key;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}
int minOperations(int *nums, int numsSize, int k) {
    HashItem *st = NULL;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) {
            return -1;
        } else if (nums[i] > k) {
            hashAddItem(&st, nums[i]);
        }
    }
    int ret = HASH_COUNT(st);
    hashFree(&st);
    return ret;
}

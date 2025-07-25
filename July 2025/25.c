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

int maxSum(int *nums, int numsSize) {
    HashItem *positiveNumsSet = NULL;
    int maxNum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            hashAddItem(&positiveNumsSet, nums[i]);
        }
        maxNum = fmax(maxNum, nums[i]);
    }
    if (HASH_COUNT(positiveNumsSet) == 0) {
        hashFree(&positiveNumsSet);
        return maxNum;
    }
    int sum = 0;
    for (HashItem *pEntry = positiveNumsSet; pEntry; pEntry = pEntry->hh.next) {
        sum += pEntry->key;
    }
    hashFree(&positiveNumsSet);
    return sum;
}

typedef struct {
    int* tree;
    int size;
} FenwickTree;

FenwickTree* fenwickTreeCreate(int size) {
    FenwickTree* obj = (FenwickTree*)malloc(sizeof(FenwickTree));
    obj->tree = (int*)calloc(size + 1, sizeof(int));
    obj->size = size;
    return obj;
}

void fenwickTreeUpdate(FenwickTree* obj, int index, int delta) {
    index++;
    while (index <= obj->size) {
        obj->tree[index] += delta;
        index += index & -index;
    }
}

int fenwickTreeQuery(FenwickTree* obj, int index) {
    index++;
    int res = 0;
    while (index > 0) {
        res += obj->tree[index];
        index -= index & -index;
    }
    return res;
}

void fenwickTreeFree(FenwickTree* obj) {
    free(obj->tree);
    free(obj);
}

long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int *pos2 = (int*)malloc(n * sizeof(int)),
        *reversedIndexMapping = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pos2[nums2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        reversedIndexMapping[pos2[nums1[i]]] = i;
    }
    FenwickTree* tree = fenwickTreeCreate(n);
    long long res = 0;
    for (int value = 0; value < n; value++) {
        int pos = reversedIndexMapping[value];
        int left = fenwickTreeQuery(tree, pos);
        fenwickTreeUpdate(tree, pos, 1);
        int right = (n - 1 - pos) - (value - left);
        res += (long long)left * right;
    }
    free(pos2);
    free(reversedIndexMapping);
    fenwickTreeFree(tree);
    return res;
}

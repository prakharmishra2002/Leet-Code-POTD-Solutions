int maxCandies(int* status, int statusSize, int* candies, int candiesSize,
               int** keys, int keysSize, int* keysColSize, int** containedBoxes,
               int containedBoxesSize, int* containedBoxesColSize,
               int* initialBoxes, int initialBoxesSize) {
    int n = statusSize;
    bool* canOpen = (bool*)calloc(n, sizeof(bool));
    bool* hasBox = (bool*)calloc(n, sizeof(bool));
    bool* used = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; ++i) {
        canOpen[i] = (status[i] == 1);
    }
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int ans = 0;
    for (int i = 0; i < initialBoxesSize; ++i) {
        int box = initialBoxes[i];
        hasBox[box] = true;
        if (canOpen[box]) {
            queue[rear++] = box;
            used[box] = true;
            ans += candies[box];
        }
    }
    while (front < rear) {
        int bigBox = queue[front++];
        for (int i = 0; i < keysColSize[bigBox]; ++i) {
            int key = keys[bigBox][i];
            canOpen[key] = true;
            if (!used[key] && hasBox[key]) {
                queue[rear++] = key;
                used[key] = true;
                ans += candies[key];
            }
        }
        for (int i = 0; i < containedBoxesColSize[bigBox]; ++i) {
            int box = containedBoxes[bigBox][i];
            hasBox[box] = true;
            if (!used[box] && canOpen[box]) {
                queue[rear++] = box;
                used[box] = true;
                ans += candies[box];
            }
        }
    }
    free(canOpen);
    free(hasBox);
    free(used);
    free(queue);
    return ans;
}

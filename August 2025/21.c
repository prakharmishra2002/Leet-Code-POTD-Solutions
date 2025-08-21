int numSubmat(int** mat, int matSize, int* matColSize) {
    int m = matSize, n = matColSize[0];
    int res = 0;
    int** row = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        row[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                row[i][j] = mat[i][j];
            } else {
                row[i][j] = mat[i][j] == 0 ? 0 : row[i][j - 1] + 1;
            }
            int cur = row[i][j];
            for (int k = i; k >= 0; k--) {
                cur = cur < row[k][j] ? cur : row[k][j];
                if (cur == 0) {
                    break;
                }
                res += cur;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        free(row[i]);
    }
    free(row);
    return res;
}

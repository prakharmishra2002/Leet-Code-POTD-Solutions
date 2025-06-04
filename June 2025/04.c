char *answerString(char *word, int numFriends) {
    int n = strlen(word);
    char *res = (char *)malloc(n + 1);
    memset(res, 0, n + 1);
    if (numFriends == 1) {
        strcpy(res, word);
        return res;
    }
    for (int i = 0; i < n; i++) {
        int j = fmin(i + n - numFriends + 1, n);
        if (strncmp(res, word + i, j - i) < 0) {
            strncpy(res, word + i, j - i);
            res[j - i] = '\0';
        }
    }
    return res;
}

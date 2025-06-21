int minimumDeletions(char* word, int k) {
    int cnt[26] = {0};
    for (int i = 0; word[i]; i++) {
        cnt[word[i] - 'a']++;
    }
    int res = strlen(word);
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        int a = cnt[i];
        int deleted = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] == 0) {
                continue;
            }
            int b = cnt[j];
            if (a > b) {
                deleted += b;
            } else if (b > a + k) {
                deleted += b - (a + k);
            }
        }
        if (deleted < res) {
            res = deleted;
        }
    }
    return res;
}

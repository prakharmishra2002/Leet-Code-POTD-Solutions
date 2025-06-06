char* robotWithString(char* s) {
    int cnt[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
    }

    char* stack = (char*)malloc(len * sizeof(char));
    int top = 0;
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;
    char minCharacter = 'a';
    for (int i = 0; i < len; i++) {
        stack[top++] = s[i];
        cnt[s[i] - 'a']--;
        while (minCharacter != 'z' && cnt[minCharacter - 'a'] == 0) {
            minCharacter++;
        }
        while (top > 0 && stack[top - 1] <= minCharacter) {
            res[pos++] = stack[--top];
        }
    }

    res[pos] = '\0';
    free(stack);
    return res;
}

int maxDifference(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    int maxOdd = 1, minEven = len;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            if (count[i] % 2 == 1) {
                maxOdd = fmax(maxOdd, count[i]);
            } else {
                minEven = fmin(minEven, count[i]);
            }
        }
    }
    return maxOdd - minEven;
}

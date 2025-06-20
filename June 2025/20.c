int count(int drt1, int drt2, int times) {
    return abs(drt1 - drt2) + times * 2;
}  // Calculate modified Manhattan distance

int maxDistance(char* s, int k) {
    int ans = 0;
    int north = 0, south = 0, east = 0, west = 0;
    for (char* p = s; *p != '\0'; p++) {
        char it = *p;
        switch (it) {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'E':
                east++;
                break;
            case 'W':
                west++;
                break;
        }

        int times1 =
            fmin(fmin(north, south), k);  // modification times for N and S
        int times2 = fmin(fmin(east, west),
                          k - times1);  // modification times for E and W
        int current = count(north, south, times1) + count(east, west, times2);
        if (current > ans) {
            ans = current;
        }
    }

    return ans;
}

int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets,
                        int basketsSize) {
    int count = 0;
    for (int j = 0; j < fruitsSize; j++) {
        int unset = 1;
        for (int i = 0; i < basketsSize; i++) {
            if (fruits[j] <= baskets[i]) {
                baskets[i] = 0;
                unset = 0;
                break;
            }
        }
        count += unset;
    }
    return count;
}

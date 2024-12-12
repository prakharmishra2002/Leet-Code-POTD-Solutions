class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Initialize the index of the richest pile (maximum element)
            int richestPileIndex = 0;

            // Iterate through the array to find the index of the maximum
            // element
            for (int currentPileIndex = 0; currentPileIndex < n;
                 currentPileIndex++) {
                // If we find a new maximum, update the index
                if (gifts[richestPileIndex] < gifts[currentPileIndex]) {
                    richestPileIndex = currentPileIndex;
                }
            }

            // Replace the richest pile with the floor of its square root
            gifts[richestPileIndex] = sqrt(gifts[richestPileIndex]);
        }

        // Calculate the sum of the remaining gifts in the array
        long long int numberOfRemainingGifts =
            accumulate(gifts.begin(), gifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};
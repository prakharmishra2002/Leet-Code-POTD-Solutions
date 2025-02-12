class Solution {
private:
    // Helper function to compute the sum of digits of a number
    int calculateDigitSum(int num) {
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
        return digitSum;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int, int>> digitSumPairs;

        // Store numbers with their digit sums as pairs
        for (int number : nums) {
            int digitSum = calculateDigitSum(number);
            digitSumPairs.push_back({digitSum, number});
        }

        // Sort based on digit sums, and if equal, by number value
        sort(digitSumPairs.begin(), digitSumPairs.end());

        int maxPairSum = -1;

        // Iterate through the sorted array to find the maximum sum of pairs
        for (int index = 1; index < digitSumPairs.size(); index++) {
            int currentDigitSum = digitSumPairs[index].first;
            int previousDigitSum = digitSumPairs[index - 1].first;

            // If two consecutive numbers have the same digit sum
            if (currentDigitSum == previousDigitSum) {
                int currentSum = digitSumPairs[index].second +
                                 digitSumPairs[index - 1].second;
                maxPairSum = max(maxPairSum, currentSum);
            }
        }

        return maxPairSum;
    }
};

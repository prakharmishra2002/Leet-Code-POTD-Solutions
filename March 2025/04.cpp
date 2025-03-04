class Solution {
public:
    bool checkPowersOfThree(int n) { return checkPowersOfThreeHelper(0, n); }

private:
    bool checkPowersOfThreeHelper(int power, int n) {
        // Base case: if n becomes 0, we have successfully formed the sum
        if (n == 0) return true;

        // If the current power of 3 exceeds n, we can't use it, so return false
        if (pow(3, power) > n) return false;

        // Option 1: Include the current power of 3 and subtract it from n
        bool addPower = checkPowersOfThreeHelper(power + 1, n - pow(3, power));

        // Option 2: Skip the current power of 3 and try with the next power
        bool skipPower = checkPowersOfThreeHelper(power + 1, n);

        // Return true if either option leads to a valid solution
        return addPower || skipPower;
    }
};

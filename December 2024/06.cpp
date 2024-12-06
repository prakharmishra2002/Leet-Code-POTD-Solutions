class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Sort banned array to enable binary search
        sort(banned.begin(), banned.end());

        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip if number is in banned array
            if (customBinarySearch(banned, num)) continue;

            maxSum -= num;

            // Break if sum exceeds our limit
            if (maxSum < 0) break;

            count++;
        }
        return count;
    }

private:
    // Helper method to check if value exists in sorted array
    bool customBinarySearch(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return true;

            if (arr[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
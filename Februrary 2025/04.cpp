class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        // Outer loop to start from each element in the array
        for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
            int currentSubarraySum = nums[startIdx];

            // Inner loop to check the next elements forming an ascending
            // subarray
            for (int endIdx = startIdx + 1;
                 endIdx < nums.size() && nums[endIdx] > nums[endIdx - 1];
                 endIdx++) {
                currentSubarraySum += nums[endIdx];
            }

            // Update maxSum if we find a larger ascending subarray sum
            maxSum = max(maxSum, currentSubarraySum);
        }

        return maxSum;
    }
};

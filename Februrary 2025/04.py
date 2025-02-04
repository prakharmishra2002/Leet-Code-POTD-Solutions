class Solution:
    def maxAscendingSum(self, nums):
        max_sum = 0

        # Outer loop to start from each element in the array
        for start_idx in range(len(nums)):
            current_subarray_sum = nums[start_idx]

            # Inner loop to check the next elements forming an ascending subarray
            end_idx = start_idx + 1
            while end_idx < len(nums) and nums[end_idx] > nums[end_idx - 1]:
                current_subarray_sum += nums[end_idx]
                end_idx += 1

            # Update max_sum if we find a larger ascending subarray sum
            max_sum = max(max_sum, current_subarray_sum)

        return max_sum

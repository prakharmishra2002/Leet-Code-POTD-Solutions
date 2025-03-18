class Solution:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        # Binary search for the longest nice subarray length
        left, right = 0, len(nums)
        result = (
            1  # Minimum answer is 1 (as subarrays of length 1 are always nice)
        )

        while left <= right:
            length = left + (right - left) // 2
            if self._can_form_nice_subarray(length, nums):
                result = length  # Update the result
                left = length + 1  # Try to find a longer subarray
            else:
                right = length - 1  # Try a shorter length

        return result

    def _can_form_nice_subarray(self, length: int, nums: list[int]) -> bool:
        if length <= 1:
            return True  # Subarray of length 1 is always nice

        # Try each possible starting position for subarray of given length
        for start in range(len(nums) - length + 1):
            bit_mask = 0  # Tracks the bits used in the current subarray
            is_nice = True

            # Check if the subarray starting at 'start' with 'length' elements is nice
            for pos in range(start, start + length):
                # If current number shares any bits with existing mask,
                # the subarray is not nice
                if bit_mask & nums[pos] != 0:
                    is_nice = False
                    break
                bit_mask |= nums[pos]  # Add current number's bits to the mask

            if is_nice:
                return True  # Found a nice subarray of the specified length

        return False  # No nice subarray of the given length exists

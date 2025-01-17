class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # Create an original array initialized with 0.
        original = [0]
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])

        # Store the validation results in checkForZero and checkForOne respectively.
        check_for_zero = original[0] == original[-1]
        original = [1]
        for i in range(len(derived)):
            original.append(derived[i] ^ original[i])
        check_for_one = original[0] == original[-1]

        return check_for_zero or check_for_one

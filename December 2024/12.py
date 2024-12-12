class Solution:
    def pickGifts(self, gifts, k):
        n = len(gifts)

        # Perform the operation k times
        for _ in range(k):
            # Initialize the index of the richest pile (maximum element)
            richest_pile_index = 0

            # Iterate through the array to find the index of the maximum element
            for currentPileIndex in range(n):
                # If we find a new maximum, update the index
                if gifts[richest_pile_index] < gifts[currentPileIndex]:
                    richest_pile_index = currentPileIndex

            # Replace the richest pile with the floor of its square root
            gifts[richest_pile_index] = math.floor(
                math.sqrt(gifts[richest_pile_index])
            )

        # Calculate the sum of the remaining gifts in the array
        number_of_remaining_gifts = sum(gifts)

        return number_of_remaining_gifts
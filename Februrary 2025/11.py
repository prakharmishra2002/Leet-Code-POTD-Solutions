class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # Continue removing occurrences of 'part' as long as it exists in 's'
        while part in s:
            # Find the index of the leftmost occurrence of 'part'
            part_start_index = s.find(part)

            # Remove the substring 'part' by concatenating segments before and after 'part'
            s = s[:part_start_index] + s[part_start_index + len(part) :]

        # Return the updated string after all occurrences are removed
        return s

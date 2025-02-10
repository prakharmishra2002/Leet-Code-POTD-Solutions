class Solution:
    def clearDigits(self, s: str) -> str:
        s = list(s)
        char_index = 0

        # Until we reach the end of the string
        while char_index < len(s):
            if s[char_index].isdigit():
                # Remove the digit from the string
                del s[char_index]
                # If there is a character to the left of the digit, remove it
                if char_index > 0:
                    del s[char_index - 1]
                    # Adjust the index to account for the removed character
                    char_index -= 1
            else:
                # Move to the next character if it's not a digit
                char_index += 1
        return "".join(s)

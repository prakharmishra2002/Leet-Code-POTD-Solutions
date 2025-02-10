class Solution {
public:
    string clearDigits(string s) {
        int charIndex = 0;

        // Until we reach the end of the string
        while (charIndex < s.size()) {
            if (isdigit(s[charIndex])) {
                // Remove the digit from the string
                s.erase(charIndex, 1);
                // If there is a character to the left of the digit, remove it
                if (charIndex > 0) {
                    s.erase(charIndex - 1, 1);
                    // Adjust the index to account for the removed character
                    charIndex--;
                }
            } else {
                // Move to the next character if it's not a digit
                charIndex++;
            }
        }
        return s;
    }
};

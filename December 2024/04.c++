class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        // Traverse through both strings using a for loop
        for (int str1Index = 0;
             str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index) {
            // Check if characters match, or if str1[str1Index] can be
            // incremented to str2[str2Index]
            if (str1[str1Index] == str2[str2Index] ||
                (str1[str1Index] + 1 == str2[str2Index]) ||
                (str1[str1Index] - 25 == str2[str2Index])) {
                // If match found, move to next character in str2
                str2Index++;
            }
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
};
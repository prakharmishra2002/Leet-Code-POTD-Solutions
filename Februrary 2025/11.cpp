class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continue removing occurrences of 'part' as long as it exists in 's'
        while (s.find(part) != string::npos) {
            // Find the index of the leftmost occurrence of 'part'
            size_t part_start_index = s.find(part);

            // Remove the substring 'part' from 's' by concatenating the
            // segments before and after 'part'
            s = s.substr(0, part_start_index) +
                s.substr(part_start_index + part.length());
        }
        // Return the updated string after all occurrences are removed
        return s;
    }
};

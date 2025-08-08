class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> lps(n, 0);  // lps[i] stores length of longest prefix-suffix for s[0..i]

        int length = 0;  // length of previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];  // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];  // last value is the LPS length for the full string
    }
};

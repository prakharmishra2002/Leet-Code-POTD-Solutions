class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        for word in words:
            count += self._has_prefix(word, pref)
        return count

    # Returns 1 if str has pref as prefix, 0 otherwise
    def _has_prefix(self, str: str, pref: str) -> int:
        itr = 0
        # Compare characters until we reach the end of either string
        while itr < len(str) and itr < len(pref):
            if str[itr] != pref[itr]:
                return 0  # Mismatch found
            itr += 1

        # Check if we've matched the entire prefix
        if itr != len(pref):
            return 0  # str is shorter than pref
        return 1

class Solution:
    def wordSubsets(self, A: 'List[str]', B: 'List[str]') -> 'List[str]':
        def count(word):
            ans = [0] * 26
            for c in word:
                ans[ord(c) - ord('a')] += 1
            return ans
        
        # simplify B
        bmax = [0] * 26
        for b in B:
            ls = count(b)
            for i in range(26):
                bmax[i] = max(bmax[i], ls[i])
        
        ans = []
        for a in A:
            ls = count(a)
            for i in range(26):
                if ls[i] < bmax[i]:
                    break
            else: # execute if the for-loop ends without break
                ans.append(a)
        return ans

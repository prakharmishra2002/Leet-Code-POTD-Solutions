class Solution:
    def totalFruit(self, f: List[int]) -> int:
        d=defaultdict(int)
        i,j,c,m=0,0,0,0
        while i<len(f):
            if d[f[i]]==0:
                c+=1
            d[f[i]]+=1
            if c==3:
                m=max(m,abs(i-j))
                while c>=3:
                    d[f[j]]-=1
                    if d[f[j]]==0:
                        c-=1
                    j+=1
            i+=1
        m=max(m,abs(i-j))
        return m         

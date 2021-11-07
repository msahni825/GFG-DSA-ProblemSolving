class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        n= len(strs)
        strs.sort()
        
        fi = strs[0]
        se = strs[n-1]
        
        for i in range(0,len(fi)):
            if fi[i] == se[i]:
                result = result+fi[i]
            else:
                return result
        return result

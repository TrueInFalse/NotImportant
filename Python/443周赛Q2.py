class Solution:
    def longestPalindrome(self, s: str, t: str) -> int:
        ns,nt=len(s),len(t)
        s,t,ans=list(s),list(t),1
        for i in range(ns):
            for j in range(i,ns):
                a,b=list(t),s[i:j+1][::-1]
                if any(a[k:k+len(b)]==b for k in range(len(a)-len(b)+1)):#s某一段在t中
                    if len(b)<ns: ans=max(ans,2*(j-i+1)+1)
                    else: ans=max(ans,2*(j-i+1))
        #接下来是寻找各自中的最长的回文串
        for i in range(ns):
            for j in range(i,ns):
                stmp=s[i:j+1]
                if stmp==stmp[::-1]: ans=max(ans,j-i+1)
        for i in range(ns):
            for j in range(i,ns):
                ttmp=t[i:j+1]
                if ttmp==ttmp[::-1]: ans=max(ans,j-i+1)
        return ans
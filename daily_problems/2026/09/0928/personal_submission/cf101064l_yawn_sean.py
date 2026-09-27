# Submission link: https://codeforces.com/gym/101064/submission/392291095
def main():
    n, S = MII()
    
    dp = [0] * 2001
    
    for _ in range(n):
        w, c = MII()
        for i in range(w, 2001):
            dp[i] = fmax(dp[i], dp[i - w] + c)
    
    def f(l, r):
        if r <= 2000: return dp[l:r + 1]
        
        nl = fmax(l // 2 - 500, 0)
        nr = r // 2 + 500
        
        v = f(nl, nr)
        ans = [0] * (r - l + 1)
        
        for i in range(nl, nr + 1):
            for j in range(i, nr + 1):
                if l <= i + j <= r:
                    ans[i + j - l] = fmax(ans[i + j - l], v[i - nl] + v[j - nl])
        
        return ans
    
    print(f(S, S)[0])
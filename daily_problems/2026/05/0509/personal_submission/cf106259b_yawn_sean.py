# Submission link: https://codeforces.com/gym/106259/submission/373890642
def main(): 
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        cnt = [0] * (n + 1)
        for x in nums:
            cnt[x] += 1
        
        res = [0] * (n + 1)
        
        dp = [0] * (n + 1)
        dp[1] = 1
        
        comb_val = 1
        
        for i in range(fmin(k, 20)):
            val = pow(cnt[1], k - 1 - i, mod) * comb_val % mod
            
            for j in range(n + 1):
                if dp[j]:
                    res[j] = (res[j] + dp[j] * val) % mod
            
            flg = True
            ndp = [0] * (n + 1)
            for j in range(1, n + 1):
                if dp[j]:
                    for w in range(2, n // j + 1):
                        if cnt[w]:
                            flg = False
                            ndp[j * w] = (ndp[j * w] + dp[j] * cnt[w] % mod) % mod
            
            if flg: break
            
            dp = ndp
            comb_val = comb_val * (k - 1 - i) % mod * pow(i + 1, -1, mod) % mod
        
        acc = cnt[:]
        for i in range(n):
            acc[i + 1] += acc[i]
    
        ans = 0
        for i in range(1, n + 1):
            for j in range(i - 1, n + 1, i):
                ans = (ans + (acc[fmin(j + i, n)] - acc[j]) * (j // i + 1) % mod * res[i] % mod) % mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
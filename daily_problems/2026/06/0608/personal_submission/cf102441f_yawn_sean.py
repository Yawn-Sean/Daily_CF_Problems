# Submission link: https://codeforces.com/gym/102441/submission/377639680
def main():
    mod = 10 ** 9 + 7
    
    n, x, y = MII()
    nums = LII()
    
    v1 = x * pow(y, -1, mod) % mod
    v0 = (mod + 1 - v1) % mod
    
    cnt = [[0] * 900 for _ in range(4)]
    
    for v in nums:
        vals = [v >> i & 1 for i in range(30)]
        
        for i in range(30):
            for j in range(30):
                cnt[vals[i] * 2 + vals[j]][i * 30 + j] += 1
    
    p0, p1 = 1, 0
    saved = [0] * (n + 1)
    
    for i in range(1, n + 1):
        p0, p1 = (p0 * v0 + p1 * v1) % mod, (p1 * v0 + p0 * v1) % mod
        saved[i] = p1
    
    ans = 0
    
    for i in range(30):
        for j in range(30):
            dp = [0] * 4
            dp[0] = 1
            
            for vi in range(2):
                for vj in range(2):
                    v = vi * 2 + vj
                    x = cnt[v][i * 30 + j]
                    
                    p1 = saved[x]
                    p0 = (mod + 1 - p1) % mod
                    
                    ndp = [0] * 4
                    
                    for idx in range(4):
                        ndp[idx] = (dp[idx ^ v] * p1 + dp[idx] * p0) % mod
                    
                    dp = ndp
            
            ans += (1 << i + j) % mod * dp[3] % mod
            ans %= mod
    
    print(ans)
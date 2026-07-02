# Submission link: https://codeforces.com/gym/106607/submission/381020073
def main():
    t = II()
    outs = []
    
    mod = 998244353
    
    for _ in range(t):
        n, m = MII()
        m += 1
    
        dp = [0] * 60
        c = 0
        
        for i in range(59, -1, -1):
            for j in range(58, -1, -1):
                dp[j + 1] += dp[j]
            if m >> i & 1:
                dp[c] += 1
                c += 1
        
        ans = 0
        for i in range(60):
            ans += dp[i] % mod * pow(n, i, mod) % mod
            ans %= mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))
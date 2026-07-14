# Submission link: https://codeforces.com/gym/103306/submission/382480010
def main():
    n, m = MII()
    
    mod = 998244353
    cnt = [1] * (1 << n)
    
    for _ in range(m):
        u, v = GMI()
        
        for i in range(1 << n):
            if i >> u & 1 and i >> v & 1:
                cnt[i] = cnt[i] * 2 % mod
    
    dp = [[0] * (1 << n) for _ in range(n + 1)]
    
    for i in range(1, 1 << n):
        bit = 1 << i.bit_length() - 1
        cur = i
        
        while cur >= bit:
            for j in range(2, n + 1):
                dp[j][i] += dp[1][cur] * dp[j - 1][i - cur] % mod
                dp[j][i] %= mod
            cur = (cur - 1) & i
        
        dp[1][i] = cnt[i]
        for j in range(2, n + 1):
            dp[1][i] -= dp[j][i]
            dp[1][i] %= mod
    
    print('\n'.join(str(dp[i][(1 << n) - 1]) for i in range(1, n + 1)))
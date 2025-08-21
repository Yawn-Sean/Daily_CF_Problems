# Submission link: https://codeforces.com/contest/1957/submission/334790894
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    dp = [0] * (3 * 10 ** 5 + 1)
    dp[0] = dp[1] = 1
    
    for i in range(2, 3 * 10 ** 5 + 1):
        dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % mod
    
    for _ in range(t):
        n, k = MII()
        for _ in range(k):
            x, y = MII()
            if x == y: n -= 1
            else: n -= 2
        outs.append(dp[n])
    
    print('\n'.join(map(str, outs)))
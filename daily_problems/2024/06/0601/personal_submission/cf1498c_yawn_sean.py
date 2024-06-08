# Submission link: https://codeforces.com/contest/1498/submission/263587388
def main():
    def f(x, y):
        return x * (k + 1) + y

    mod = 10 ** 9 + 7
    t = II()
    outs = []

    for _ in range(t):
        n, k = MII()
        dp = [0] * ((n + 1) * (k + 1))
        
        for i in range(n + 1):
            dp[f(i, 1)] = 1
        
        for j in range(2, k + 1):
            dp[f(0, j)] = 1
            for i in range(1, n + 1):
                dp[f(i, j)] = (dp[f(i - 1, j)] + dp[f(n - i, j - 1)]) % mod
        
        outs.append(dp[f(n, k)])

    print('\n'.join(map(str, outs)))
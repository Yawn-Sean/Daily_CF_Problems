# Submission link: https://codeforces.com/contest/518/submission/305741237
def main():
    n, p, t = LI()
    n = int(n)
    p = float(p)
    t = int(t)

    dp = [0] * (n + 1)
    dp[0] = 1

    for _ in range(t):
        for i in range(n - 1, -1, -1):
            dp[i + 1] += dp[i] * p
            dp[i] *= 1 - p

    ans = 0
    for i in range(n + 1):
        ans += dp[i] * i

    print(ans)
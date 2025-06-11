# Submission link: https://codeforces.com/contest/294/submission/319575544
def main():
    n = II()
    dp = [-10 ** 6] * 201
    dp[0] = 0

    total_w = 0

    for i in range(n):
        t, w = MII()
        total_w += w
        
        for i in range(200, t - 1, -1):
            dp[i] = fmax(dp[i], dp[i - t] + w)

    for i in range(201):
        if total_w - dp[i] <= i:
            print(i)
            break
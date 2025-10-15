# Submission link: https://codeforces.com/contest/441/submission/292832081
def main():
    x, k, p = MII()

    p1 = p / 100
    p2 = 1 - p1

    dp = [[0] * (k + 1) for _ in range(k + 1)]
    for i in range(k + 1):
        v = x + i
        dp[0][i] = (v & -v).bit_length() - 1

    for i in range(k):
        for j in range(k + 1):
            if j * 2 <= k: dp[i + 1][j * 2] += p1 * (dp[i][j] + 1)
            if j > 0: dp[i + 1][j - 1] += p2 * dp[i][j]

    print(dp[k][0])
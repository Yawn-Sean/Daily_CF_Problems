# Submission link: https://codeforces.com/contest/999/submission/285099816
def main():
    n, k = MII()

    cnt = [0] * (10 ** 5 + 1)
    for c in MII():
        cnt[c] += 1

    player_cnt = [0] * (10 ** 5 + 1)
    for f in MII():
        player_cnt[f] += 1

    hs = LII()

    dp = [[0] * (n * k + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(n * k, 0, -1):
            for v in range(k):
                if j - v - 1 >= 0:
                    dp[i][j] = fmax(dp[i][j], dp[i - 1][j - v - 1] + hs[v])

    ans = 0
    for i in range(10 ** 5 + 1):
        ans += dp[player_cnt[i]][cnt[i]]
    print(ans)

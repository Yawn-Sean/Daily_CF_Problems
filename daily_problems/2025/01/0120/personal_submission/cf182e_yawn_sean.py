# Submission link: https://codeforces.com/contest/182/submission/301928869
def main():
    n, l = MII()
    xs = []
    ys = []

    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    dp = [[0] * (l + 1) for _ in range(n * 2 + 1)]
    dp[2 * n][0] = 1

    mod = 10 ** 9 + 7

    for i in range(l + 1):
        for old in range(2 * n + 1):
            for idx in range(n):
                if old // 2 != idx:
                    v = 0 if old == 2 * n else (ys[old // 2] if old % 2 else xs[old // 2])
                    if (v == 0 or xs[idx] == v) and i + xs[idx] <= l:
                        dp[idx * 2 + 1][i + xs[idx]] += dp[old][i]
                        dp[idx * 2 + 1][i + xs[idx]] %= mod
                    if xs[idx] != ys[idx] and (v == 0 or ys[idx] == v) and i + ys[idx] <= l:
                        dp[idx * 2][i + ys[idx]] += dp[old][i]
                        dp[idx * 2][i + ys[idx]] %= mod

    print(sum(dp[i][l] for i in range(2 * n + 1)) % mod)
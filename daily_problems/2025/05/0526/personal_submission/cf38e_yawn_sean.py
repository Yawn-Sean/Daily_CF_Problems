# Submission link: https://codeforces.com/contest/38/submission/321303814
def main():
    n = II()
    xs = []
    cs = []

    for _ in range(n):
        x, c = MII()
        xs.append(x)
        cs.append(c)

    order = sorted(range(n), key=lambda x: -xs[x])

    acc = [0] * (n + 1)
    for i in range(n):
        acc[i + 1] = acc[i] + xs[order[i]]

    inf = 10 ** 18
    dp = [inf] * (n + 1)

    dp[0] = 0

    for i in range(n):
        for j in range(i + 1):
            dp[i + 1] = fmin(dp[i + 1], dp[j] + cs[order[i]] + acc[i + 1] - acc[j] - xs[order[i]] * (i + 1 - j))

    print(dp[n])
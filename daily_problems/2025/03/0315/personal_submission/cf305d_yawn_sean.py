# Submission link: https://codeforces.com/contest/305/submission/310645981
def main():
    n, m, k = MII()
    vis = [0] * n

    for _ in range(m):
        u, v = MII()
        if v - u == k + 1: vis[u] = 1
        elif v - u != 1: exit(print(0))

    for i in range(1, n):
        vis[i] += vis[i - 1]

    ans = 0
    mod = 10 ** 9 + 7

    pw2 = [1] * (n + 1)
    for i in range(1, n + 1):
        pw2[i] = pw2[i - 1] + pw2[i - 1]
        if pw2[i] >= mod: pw2[i] -= mod

    if vis[-1] == 0:
        ans += 1

    for i in range(n - k - 1):
        if vis[i] == 0 and vis[i + k + 1] == vis[-1]:
            r = fmin(i + k, n - k - 2)
            ans += pw2[r - i - (vis[r + 1] - vis[i + 1])]
            if ans >= mod: ans -= mod

    print(ans)
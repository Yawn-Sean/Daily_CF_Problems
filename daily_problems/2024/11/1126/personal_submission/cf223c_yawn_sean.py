# Submission link: https://codeforces.com/contest/223/submission/293288122
def main():
    n, k = MII()
    nums = LII()

    mod = 10 ** 9 + 7

    f = [1] * (n + 1)
    for i in range(1, n + 1):
        f[i] = f[i - 1] * i % mod

    g = [1] * (n + 1)
    g[n] = pow(f[n], -1, mod)
    for i in range(n, 0, -1):
        g[i - 1] = g[i] * i % mod

    combs = [1] * n
    for i in range(1, n):
        combs[i] = combs[i - 1] * (k + i - 1) % mod * f[i - 1] % mod * g[i] % mod

    ans = [0] * n
    for i in range(n):
        for j in range(i, n):
            ans[j] += nums[i] * combs[j - i] % mod
            if ans[j] >= mod:
                ans[j] -= mod

    print(' '.join(map(str, ans)))
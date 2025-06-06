# Submission link: https://codeforces.com/contest/1866/submission/309281943
def main():
    n, k = MII()
    mod = 998244353

    ans = 0
    cur = 1

    for cnt in range(fmin(n, k) + 1):
        ans += cur * (pow(cnt + 1, k - cnt + 1, mod) - pow(cnt, k - cnt + 1, mod)) % mod
        cur = cur * (n - cnt) % mod * (cnt + 1) % mod

    print(ans % mod)
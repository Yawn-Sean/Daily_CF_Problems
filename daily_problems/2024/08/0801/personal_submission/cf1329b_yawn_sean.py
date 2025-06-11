# Submission link: https://codeforces.com/contest/1329/submission/273790341
def main():
    d, mod = MII()
    ans = 1
    tmp = 1
    while tmp <= d:
        ans *= fmin(tmp, d - tmp + 1) + 1
        ans %= mod
        tmp *= 2
    return (ans - 1) % mod
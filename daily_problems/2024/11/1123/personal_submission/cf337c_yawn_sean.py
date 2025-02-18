# Submission link: https://codeforces.com/contest/337/submission/292830556
def main():
    n, m, k = MII()
    mod = 1000000009

    v1 = fmin(m, n - n // k)
    v2 = m - v1

    v1 -= (k - 1) * v2
    print((k * (pow(2, v2 + 1, mod) - 2) + v1) % mod)
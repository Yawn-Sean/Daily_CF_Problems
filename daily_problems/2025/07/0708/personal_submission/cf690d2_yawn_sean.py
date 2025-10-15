# Submission link: https://codeforces.com/contest/690/submission/328010714
def main():
    mod = 10 ** 6 + 3

    n, c = MII()
    v1 = 1
    v2 = 1

    for i in range(1, c + 1):
        v1 = v1 * (n + c + 1 - i) % mod
        v2 = v2 * i % mod

    print((v1 * pow(v2, -1, mod) % mod - 1) % mod)
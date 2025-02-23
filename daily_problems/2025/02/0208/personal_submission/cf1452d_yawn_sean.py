# Submission link: https://codeforces.com/contest/1452/submission/304915710
def main():
    n = II()
    mod = 998244353

    a, b = 0, 1
    for _ in range(n):
        a, b = b, (a + b) % mod

    print(a * pow(2, -n, mod) % mod)
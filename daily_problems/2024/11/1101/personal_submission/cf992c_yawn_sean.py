# Submission link: https://codeforces.com/contest/992/submission/289073974
def main():
    x, k = MII()
    mod = 10 ** 9 + 7
    print((pow(2, k, mod) * (2 * x - 1) % mod + 1) % mod if x else 0)
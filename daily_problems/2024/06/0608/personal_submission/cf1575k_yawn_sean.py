# Submission link: https://codeforces.com/contest/1575/submission/264662308
def main():
    n, m, k, r, c = MII()
    ax, ay, bx, by = MII()
    mod = 10 ** 9 + 7
    print(pow(k, n * m - r * c * (ax != bx or ay != by), mod))
# Submission link: https://codeforces.com/contest/1009/submission/286300778
def main():
    n, q = MII()

    v1 = n * (n - 1) // 2
    v2 = sum(abs(i - n // 2) for i in range(n))

    ans = 0
    tot = 0

    for _ in range(q):
        x, y = MII()
        ans += x
        tot += y * (v1 if y >= 0 else v2)

    print(ans + tot / n)
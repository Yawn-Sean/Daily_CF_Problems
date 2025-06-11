# Submission link: https://codeforces.com/contest/449/submission/279732101
def main():
    def f(x):
        return x * (m // fmax(1, k - n // x + 2))

    n, m, k = MII()
    ans = 0
    for i in range(1, fmin(n + 1, 40000)):
        ans = fmax(ans, f(i))
        ans = fmax(ans, f(n // i))

    print(ans if ans else -1)

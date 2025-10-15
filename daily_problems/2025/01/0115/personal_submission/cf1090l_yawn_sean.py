# Submission link: https://codeforces.com/contest/1043/submission/301036401
def main():
    t, n, a, b, k = MII()
    v2 = n // 2
    v1 = n - v2

    ans = fmin(t, (v1 * a + v2 * b) // k)
    if k > v1: ans = fmin(ans, v2 * b // (k - v1))
    if k > v2: ans = fmin(ans, v1 * a // (k - v2))

    print(ans if k <= n else 0)
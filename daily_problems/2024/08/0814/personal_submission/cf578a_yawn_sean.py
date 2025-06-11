# Submission link: https://codeforces.com/contest/578/submission/276331377
def main():
    x, y = MII()
    if y > x: print(-1)
    else:
        ans = 10 ** 9
        v = x - y
        if v >= 2 * y:
            k = v // (2 * y)
            ans = fmin(ans, v / 2 / k)
        v = x + y
        if v >= 2 * y:
            k = v // (2 * y)
            ans = fmin(ans, v / 2 / k)
        print(ans)
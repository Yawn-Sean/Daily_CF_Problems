# Submission link: https://codeforces.com/contest/1292/submission/265552710
def main():
    x0, y0, ax, ay, bx, by = MII()
    x_start, y_start, t = MII()

    xs = []
    ys = []

    x, y = x0, y0

    while x + y - x_start - y_start <= t:
        xs.append(x)
        ys.append(y)
        x = ax * x + bx
        y = ay * y + by

    n = len(xs)
    ans = 0
    for i in range(n):
        for j in range(i + 1):
            for k in range(i, n):
                if abs(x_start - xs[i]) + abs(y_start - ys[i]) + \
                    + min(xs[k] - xs[i] + ys[k] - ys[i], xs[i] - xs[j] + ys[i] - ys[j]) + \
                    xs[k] - xs[j] + ys[k] - ys[j] <= t:
                    ans = max(ans, k - j + 1)

    print(ans)
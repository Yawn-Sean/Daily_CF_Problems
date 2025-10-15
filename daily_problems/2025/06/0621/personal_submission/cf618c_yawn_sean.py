# Submission link: https://codeforces.com/contest/618/submission/325341513
def main():
    n = II()
    xs = []
    ys = []

    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    def area(i, j, k):
        dx1, dy1 = xs[j] - xs[i], ys[j] - ys[i]
        dx2, dy2 = xs[k] - xs[i], ys[k] - ys[i]
        return abs(dx1 * dy2 - dy1 * dx2)

    chosen = -1
    for i in range(n):
        if area(0, 1, i) and (chosen == -1 or area(0, 1, i) < area(0, 1, chosen)):
            chosen = i

    a = 0
    b = chosen

    chosen = -1
    for i in range(n):
        if area(a, b, i) and (chosen == -1 or area(a, b, i) < area(a, b, chosen)):
            chosen = i

    print(a + 1, b + 1, chosen + 1)
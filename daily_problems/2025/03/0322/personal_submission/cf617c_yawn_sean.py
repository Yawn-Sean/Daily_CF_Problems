# Submission link: https://codeforces.com/contest/617/submission/311729185
def main():
    n, x1, y1, x2, y2 = MII()

    def d1(x, y):
        return (x - x1) * (x - x1) + (y - y1) * (y - y1)

    def d2(x, y):
        return (x - x2) * (x - x2) + (y - y2) * (y - y2)

    ans = 0
    xs = []
    ys = []
    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)
        ans = fmax(ans, d2(x, y))

    for i in range(n):
        r1 = d1(xs[i], ys[i])
        r2 = 0
        
        for j in range(n):
            if d1(xs[j], ys[j]) > r1:
                r2 = fmax(r2, d2(xs[j], ys[j]))
        
        ans = fmin(ans, r1 + r2)

    print(ans)
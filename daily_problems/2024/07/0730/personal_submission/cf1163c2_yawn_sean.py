# Submission link: https://codeforces.com/contest/1163/submission/273407160
def main():
    n = II()
    xs = []
    ys = []

    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    lines = set()
    for i in range(n):
        for j in range(i):
            dx = xs[i] - xs[j]
            dy = ys[i] - ys[j]
            g = math.gcd(dx, dy)
            dx //= g
            dy //= g
            if dx < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            lines.add((dx, dy, xs[i] * dy - ys[i] * dx))

    k = len(lines)
    ans = k * (k - 1) // 2
    cnt = Counter()

    for x, y, d in lines:
        ans -= cnt[(x, y)]
        cnt[(x, y)] += 1

    print(ans)
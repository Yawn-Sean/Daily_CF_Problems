# Submission link: https://codeforces.com/contest/183/submission/328252970
def main():
    n, m = MII()
    xs = []
    ys = []

    for _ in range(m):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    cnt = Counter()

    for i in range(m):
        x1, y1 = xs[i], ys[i]
        for j in range(i):
            x2, y2 = xs[j], ys[j]
            dx, dy = x2 - x1, y2 - y1
            
            g = math.gcd(dx, dy)
            dx //= g
            dy //= g
            
            if dx < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            
            cnt[(dx, dy, x1 * dy - dx * y1)] += 1

    ans = [0] * (n + 1)

    for dx, dy, val in cnt:
        v = cnt[(dx, dy, val)]
        if dy and val % dy == 0 and 1 <= val // dy <= n:
            ans[val // dy] = fmax(ans[val // dy], v)

    res = 0
    for i in range(1, n + 1):
        res += math.isqrt(ans[i] * 2) + 1

    print(res)
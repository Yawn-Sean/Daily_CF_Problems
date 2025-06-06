# Submission link: https://codeforces.com/contest/552/submission/319316222
def main():
    n = II()

    xs = []
    ys = []

    for _ in range(n):
        x, y = MII()
        xs.append(x)
        ys.append(y)

    ans = n * (n - 1) * (n - 2) // 6

    for i in range(n):
        cnt = Counter()
        
        for j in range(i):
            dx = xs[j] - xs[i]
            dy = ys[j] - ys[i]
            
            g = math.gcd(dx, dy)
            dx //= g
            dy //= g
            
            if dx < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            
            ans -= cnt[(dx, dy)]
            cnt[(dx, dy)] += 1

    print(ans)
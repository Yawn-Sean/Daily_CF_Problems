def main():
    n = II()
    ans = 0
    cnt = Counter()
    for _ in range(n):
        x, y, u, v = MII()
        dx = u - x
        dy = v - y
        g = math.gcd(dx, dy)
        dx //= g
        dy //= g
        ans += cnt[(dx, dy)]
        cnt[(-dx, -dy)] += 1
    print(ans)
    return


t = II()
for _ in range(t):
    main()

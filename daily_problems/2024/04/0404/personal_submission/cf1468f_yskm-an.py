t = int(input())
for _ in range(t):
    n = int(input())
    find = Counter()
    res = 0
    for _ in range(n):
        x, y, u, v = map(int, input().split())
        dx, dy = u - x, v - y
        p = gcd(dx, dy)
        dx //= p
        dy //= p
        res += find[(-dx, -dy)]
        find[(dx, dy)] += 1
    print(res)

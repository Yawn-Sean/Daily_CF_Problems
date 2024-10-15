def CF975D():
    n, a, b = MII()
    ans = 0
    vis1 = defaultdict(int)
    vis2 = defaultdict(lambda : defaultdict(int))
    for _ in range(n):
        x, vx, vy = MII()
        ans += vis1[(a * vx - vy) ^ RD] - vis2[vx][vy]
        vis1[(a * vx - vy) ^ RD] += 1
        vis2[vx][vy] += 1
    print(ans << 1)

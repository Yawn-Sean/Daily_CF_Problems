n, k, b = MII()
vs = [None] * n
for i in range(n):
    _, vx, vy = MII()
    vs[i] = (vx, vy)

"""
对于两个点 (x0, y0), (x1, y1)
x0 + vx0 * t = x1 + vx1 * t & y0 + vy0 * t = y1 + vy1 * t
(vx0 - vx1) / (x0 - x1) = (vy0 - vy1) / (y0 - y1)
y = kx + b
k * (vx0 - vx1) = vy0 - vy1
k * vx0 - vy0 = k * vx1 - vy1
"""

d = defaultdict(list)
for vx, vy in vs:
    d[k * vx - vy].append(vx)

ans = 0
for c in d.values():
    tot = len(c)
    cnt = Counter(c)
    for v in cnt.values():
        ans += v * (tot - v)

print(ans)

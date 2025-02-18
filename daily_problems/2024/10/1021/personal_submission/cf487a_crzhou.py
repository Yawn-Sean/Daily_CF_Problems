hx, ax, dx = map(int, input().split())
hy, ay, dy = map(int, input().split())
h, a, d = map(int, input().split())

res = float('inf')
for i in range(max(0, (dy - ax) + 1), max(hy - (ax - dy), 0) + 1):
    for j in range(0, max(ay - dx, 0) + 1):
        ycnt = ceil(hy, ax - dy + i)
        if ay - dx - j <= 0:
            res = min(res, i * a + j * d)
            continue
        l = max(0, (ay - dx - j) * ycnt + 1 - hx)
        res = min(res, i * a + j * d + l * h)

print(res)

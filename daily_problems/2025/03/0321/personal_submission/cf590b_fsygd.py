[x1, y1, x2, y2] = list(map(int, input().split(' ')))
x2, y2 = x2 - x1, y2 - y1
[v, t] = list(map(int, input().split(' ')))
[vx, vy] = list(map(int, input().split(' ')))
[wx, wy] = list(map(int, input().split(' ')))

l, r = 0, 10 ** 9
while r - l > 10 ** -8:
    m = (l + r) / 2
    x, y = x2, y2
    x -= min(m, t) * vx
    y -= min(m, t) * vy
    x -= max(m - t, 0) * wx
    y -= max(m - t, 0) * wy
    if m * m * v * v > x * x + y * y:
        r = m
    else:
        l = m
print(l)
y1, y2, yw, xb, yb, r = map(float, input().split())
yb = (yw - r) * 2 - yb
y3 = y1 + r
k = (yb - y3) / xb
if (y2 - y3) / (1 + k**2)**0.5 <= r:
    print(-1)
else:
    print((yw - r - y3) / k)
import random

n = int(input())
xs = []
ys = []
rs = []

for i in range(n):
    x, y, r = map(int, input().split())
    xs.append(x)
    ys.append(y)
    rs.append(r)

def in_circle(x, y, r, xx, yy):
    return (x - xx) ** 2 + (y - yy) ** 2 <= r ** 2

down, up = -10, 20
left, right = -10, 20

cnt = 10 ** 6
cnt_in = 0
for i in range(cnt):
    x = random.uniform(down, up)
    y = random.uniform(left, right)
    ok = 0
    for j in range(n):
        if in_circle(x, y, rs[j], xs[j], ys[j]):
            ok = 1
    cnt_in += ok

print(cnt_in / cnt * (up - down) * (right - left))

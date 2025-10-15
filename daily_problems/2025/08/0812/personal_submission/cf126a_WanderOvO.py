"""
t1 * y1 + t2 * y2 >= t0 * (y1 + y2)
枚举 y1, 则 (t0 - t1) * y1 <= (t2 - t0) * y2
y2 >= (t0 - t1) * y1 / (t2 - t0), t2 > t0
y2 <= (t0 - t1) * y1 / (t2 - t0), t2 < t0
如果 t2 = t0，则 t2 水管无脑拉到最大就好了
假如这个时候 t1 = t0，则都无脑拉到最大
如果 t1 != t0，则 t1 不能贡献，否则不够接近
按照不等号去取整，如果在范围内则 y2 就是这个
如果 y2 不在范围内:
- t2 > t0，则不行了
- t2 < t0，则可以取 y2 = x2
"""
import math

t1, t2, x1, x2, t0 = map(int, input().split())

if t2 == t0:
    if t1 == t2:
        print(x1, x2)
    else:
        print(0, x2)
    exit(0)

if t1 == t0:
    if t2 == t1:
        print(x1, x2)
    else:
        print(x1, 0)
    exit(0)

resy1, resy2 = -1, -1
d2 = 1e18
eps = 1e-8
if t2 >= t0:
    resy1 = 0
    resy2 = x2
    d2 = t2 - t0
for y1 in range(1, x1 + 1):
    if t2 > t0:
        y2 = math.ceil((t0 - t1) * y1 / (t2 - t0))
    else:
        y2 = math.floor((t0 - t1) * y1 / (t2 - t0))
    if not (y2 >= 0 and y2 <= x2):
        if t2 < t0:
            y2 = x2
    if y2 >= 0 and y2 <= x2:
        if resy1 == -1:
            if y1 + y2 != 0:
                resy1 = y1
                resy2 = y2
        else:
            if y1 + y2 == 0:
                continue
            else:
                d1 = (t1 * y1 + t2 * y2) / (y1 + y2) - t0
            # assert d1 >= 0
            if d1 < d2:
                resy1 = y1
                resy2 = y2
                d2 = d1

            elif math.fabs(d1 - d2) < eps and (y1 + y2) > (resy1 + resy2):
                resy1 = y1
                resy2 = y2

print(resy1, resy2)

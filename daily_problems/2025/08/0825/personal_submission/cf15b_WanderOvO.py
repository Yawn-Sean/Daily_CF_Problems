"""
往上可以移动的距离：min(x[1], x[2]) - 1
往下可以移动的距离：n - max(x[1], x[2])
往左可以移动的距离：min(y[1], y[2]) - 1
往右可以移动的距离：m - max(y[1], y[2])
我们根据算出来的最大移动距离，可以算出每束激光能到的左上角和右下角的点
再算出二者的交即可
"""
import sys

input = lambda: sys.stdin.readline().strip()

T = int(input())
while T > 0:
    T -= 1
    n, m, x1, y1, x2, y2 = map(int, input().split())
    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1
    if x1 == x2:
        if y1 > y2:
            x1, x2 = x2, x1
            y1, y2 = y2, y1

    up = min(x1, x2) - 1
    down = n - max(x1, x2)
    left = min(y1, y2) - 1
    right = m - max(y1, y2)

    up_x1 = x1 - up
    up_x2 = x2 - up
    down_x1 = x1 + down
    down_x2 = x2 + down
    left_y1 = y1 - left
    left_y2 = y2 - left
    right_y1 = y1 + right
    right_y2 = y2 + right

    area1 = (down_x1 - up_x1 + 1) * (right_y1 - left_y1 + 1)
    area2 = (down_x2 - up_x2 + 1) * (right_y2 - left_y2 + 1)

    res = area1 + area2
    if up_x2 <= down_x1:
        if y1 <= y2 and right_y1 >= left_y2:
            res -= (right_y1 - left_y2 + 1) * (down_x1 - up_x2 + 1)
        elif y1 >= y2 and right_y2 >= left_y1:
            res -= (right_y2 - left_y1 + 1) * (down_x1 - up_x2 + 1)
    assert res >= 0 and res <= n * m
    print(n * m - res)

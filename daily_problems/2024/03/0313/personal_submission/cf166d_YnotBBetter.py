import bisect

import math


def main():
    m = int(input())
    points = [list(map(int, input().split())) for _ in range(m)]
    l, r = min(points), max(points)
    li, ri = points.index(l), points.index(r)
    upper = points[li:ri+1] if li < ri else points[li:] + points[:ri+1]
    lower = list(reversed(points[ri:] + points[:li+1])) if li < ri else list(reversed(points[ri:li+1]))
    xl, xr = min(x for x, y in points), max(x for x, y in points)

    n = int(input())
    for _ in range(n):
        x, y = list(map(int, input().split()))
        if x <= xl or x >= xr:
            print("NO")
            return
        idx = bisect.bisect_left(upper, [x, y])
        [x1, y1], [x2, y2] = upper[idx-1], upper[idx]
        if (y - y1) * (x2 - x1) >= (y2 - y1) * (x - x1):
            print("NO")
            return
        idx = bisect.bisect_left(lower, [x, y])
        [x1, y1], [x2, y2] = lower[idx-1], lower[idx]
        if (y - y1) * (x2 - x1) <= (y2 - y1) * (x - x1):
            print("NO")
            return
    print("YES")


main()

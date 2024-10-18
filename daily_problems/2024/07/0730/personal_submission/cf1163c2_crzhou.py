import math
from collections import defaultdict

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def main():
    n = int(input().strip())
    points = []
    for _ in range(n):
        x, y = map(float, input().strip().split())
        points.append(Point(x, y))

    ans = 0
    tot = 0
    mp = defaultdict(set)

    for i in range(n):
        for j in range(i):
            d1 = points[i].y - points[j].y
            d2 = points[i].x - points[j].x
            d3 = points[j].x * points[i].y - points[i].x * points[j].y
            dls = math.gcd(int(d1), int(d2))
            d1 /= dls
            d2 /= dls
            if d1 < 0 or (d1 == 0 and d2 < 0):
                d1 = -d1
                d2 = -d2
            d3 = d2 * points[j].y - d1 * points[j].x
            k = (d1, d2)
            if d3 not in mp[k]:
                ans += tot - len(mp[k])
                tot += 1
                mp[k].add(d3)

    print(ans)

if __name__ == "__main__":
    main()

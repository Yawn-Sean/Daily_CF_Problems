from math import gcd
from collections import Counter
def main():
    n = int(input())
    g = []
    for _ in range(n):
        x,y = map(int,input().split())
        g.append((x,y))
    lines = set()
    for i in range(n):
        for j in range(i):
            dx = g[i][0] - g[j][0]
            dy = g[i][1] - g[j][1]
            gcd_ = gcd(dx,dy)
            dx //= gcd_
            dy //= gcd_
            if dy < 0 or (dx == 0 and dy < 0):
                dx = -dx
                dy = -dy
            lines.add((dx,dy,g[i][0]*dy - g[i][1]*dx))
    r = len(lines)
    ans = r * (r-1) // 2
    c = Counter()
    for x,y,d in lines:
        ans -= c[(x,y)]
        c[(x,y)] += 1
    print(ans)

main()
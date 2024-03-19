import math
import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
points = [list(map(int, input().split())) for _ in range(n)]

ans = math.inf
for i in range(n):
    x1, y1 = points[i]
    x2, y2 = points[(i + 1) % n]
    x3, y3 = points[(i + 2) % n]
    area = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2
    ans = min(ans, area / math.sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2))
print(ans)

import sys

import math

input = lambda: sys.stdin.readline().strip()

# 这题不会
# 给定饭店的坐标(x0, y0), 要求每个旅店到此点的距离最大值
# max_dist = max(|x - x0| + |y - y0|) for all (x, y)
#          = max(x - x0 + y - y0, x - x0 + y0 - y, x0 - x + y - y0, x0 - x + y0 - y)
#          = max((x + y) - (x0 + y0), (x - y) - (x0 - y0), (x0 - y0) - (x - y), (x0 + y0) - (x + y))
#          = max(max(x + y) - (x0 + y0), max(x - y) - (x0 - y0), (x0 - y0) - min(x - y), (x0 + y0) - min(x + y))
# 这里 (x0, y0) 是固定值，max(x + y)、max(x - y)、min(x - y)、min(x + y) 预处理即可得到

m, n = map(int, input().split())

min_sum, max_sum = math.inf, -math.inf
min_diff, max_diff = math.inf, -math.inf

h = int(input())
for _ in range(h):
    x, y = map(int, input().split())
    min_sum, max_sum = min(min_sum, x + y), max(max_sum, x + y)
    min_diff, max_diff = min(min_diff, x - y), max(max_diff, x - y)

ans, idx = math.inf, -1
r = int(input())
for i in range(r):
    x, y = map(int, input().split())
    d = max(max_sum - x - y, max_diff - x + y, x - y - min_diff, x + y - min_sum)
    if d < ans:
        ans, idx = d, i + 1

print(ans)
print(idx)

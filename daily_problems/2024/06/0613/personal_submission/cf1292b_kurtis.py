import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

x0, y0, ax, ay, bx, by = MII()
x_start, y_start, t = MII()

xs, ys = [], []
x, y = x0, y0 # 起始点
while x + y - x_start - y_start <= t:
    xs.append(x)
    ys.append(y)
    x, y = ax * x + bx, ay * y + by

n = len(xs)
ans = 0
# 暴力枚举
for i in range(n): # 第一个点
    for j in range(i + 1): # 包括i的左端点
        for k in range(i, n): # 包括i的右端点
            d = abs(xs[i] - x_start) + abs(ys[i] - y_start)
            d += min(xs[i] + ys[i] - xs[j] - ys[j], xs[k] + ys[k] - xs[i] - ys[i])
            d += xs[k] + ys[k] - xs[j] - ys[j]
            if d <= t: ans = max(ans, k - j + 1)
print(ans)
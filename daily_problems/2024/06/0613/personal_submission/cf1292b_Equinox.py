import sys

sys.stdin = open('in.txt', 'r')

x0, y0, ax, ay, bx, by = map(int, input().split())

xs, ys, t = map(int, input().split())

res = 0

x, y = [], []

while x0 + y0 - xs - ys <= t:
    x.append(x0)
    y.append(y0)
    x0 = ax * x0 + bx
    y0 = ay * y0 + by

n = len(x)

for i in range(n):
    for j in range(i + 1):
        for k in range(i, n):
            if abs(xs - x[i]) + abs(ys - y[i]) + min(x[k] + y[k] - x[i] - y[i], x[i] + y[i] - x[j] - y[j]) + \
                   x[k] + y[k] - x[j] - y[j] <= t:
                res = max(res, k - j + 1)


print(res)
import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
c = int(input())
xy0 = x_y0 = 1e10
xy1 = x_y1 = -1e10
for _ in range(c):
    x, y = map(int, input().split())
    xy0 = min(xy0, x+y)
    x_y0 = min(x_y0, x-y)
    xy1 = max(xy1, x+y)
    x_y1 = max(x_y1, x-y)

h = int(input())
ans = 1e10
ansi = -1
for _ in range(h):
    x, y = map(int, input().split())
    k = max(x+y-xy0, xy1-x-y, x-y-x_y0, x_y1-(x-y))
    if ans > k:
        ans = k
        ansi = _
print(ans)
print(ansi+1)

import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
points = [[x0, y0]]
while points[-1][0] <= 10 ** 16 and points[-1][1] <= 10 ** 16:
    points.append([points[-1][0] * ax + bx, points[-1][1] * ay + by])

ans = 0
for i, [in_x, in_y] in enumerate(points):
    now = t - abs(in_x - xs) - abs(in_y - ys)
    for j, [left_x, left_y] in enumerate(points[: i + 1]):
        for k, [right_x, right_y] in enumerate(points[i:]):
            if now - (right_x - left_x + right_y - left_y) - min((in_x - left_x + in_y - left_y), (right_x - in_x + right_y - in_y)) >= 0:
                ans = max(ans, k + (i - j) + 1)
print(ans)


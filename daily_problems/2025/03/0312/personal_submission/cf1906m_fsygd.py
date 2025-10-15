_ = input()
points = list(map(int, input().split(" ")))
m, s = max(points), sum(points)
print((s - m) if m >= 2 * (s - m) else s // 3)
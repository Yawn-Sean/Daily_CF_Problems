"""
排序，枚举所有 a 和 b，额外加一个 0
"""

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

c = a + b
c.append(0)
c.sort()
a.sort()
b.sort()

p1, p2 = -1, -1
max_ch = -int(1e18)
max_a = 0
max_b = 0
for d in c:
    while p1 + 1 < n and a[p1 + 1] <= d:
        p1 += 1
    while p2 + 1 < m and b[p2 + 1] <= d:
        p2 += 1
    val_a = (p1 + 1) * 2 + (n - p1 - 1) * 3
    val_b = (p2 + 1) * 2 + (m - p2 - 1) * 3
    if val_a - val_b > max_ch:
        max_ch = val_a - val_b
        max_a = val_a
        max_b = val_b

print(f'{max_a}:{max_b}')

"""
\sum x_i*t_i = T*\sum x_i  <=> \sum x_i*(t_i-T)=0 。以下以 t_i-T 代替 t_i 。
按 t_i 的正负性分为 pos 和 neg 两组（ t_i=0 时将 x_i 直接添加至答案）。根据贪心的思想， |t_i| 越小则能贡献的 x_i 越大。所以将 pos 和 neg 根据 |t_i| 排序，利用双指针计算答案即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

_, T = lii()
arr = lii()
temp = [t-T for t in lii()]
pos, neg = [], []
ans = 0
for x, t in zip(arr, temp):
    if t > 0:
        pos.append([x, t])
    elif t < 0:
        neg.append([x, -t])
    else:
        ans += x
pos.sort(key=lambda p: p[1])
neg.sort(key=lambda p: p[1])

m, n = len(pos), len(neg)
i, j = 0, 0
while i < m and j < n:
    x1, t1 = pos[i]
    x2, t2 = neg[j]
    if x1*t1 > x2*t2:
        tmp = x2*t2/t1
        pos[i][0] -= tmp
        j += 1
        ans += x2 + tmp
    else:
        tmp = x1*t1/t2
        neg[j][0] -= tmp
        i += 1
        ans += x1 + tmp

print(ans)
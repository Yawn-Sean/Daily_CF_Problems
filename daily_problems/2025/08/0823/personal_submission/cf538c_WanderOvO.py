"""
每两个给出的之间，看看至多能到多少
d[i] 天到 h[i]，d[i + 1] 天到 h[i + 1]
差 d[i + 1] - d[i] 天，二者的差距是 h[i + 1] - h[i]
如果 h[i + 1] >= h[i]，考虑先升后减
如果 h[i + 1] < h[i]，考虑先升后减
考虑枚举 h[i] + 1, h[i] + 2...，然后看看剩下的步数还能不能走到 h[i + 1]
"""
import sys

input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
ds = []
hs = []
for i in range(m):
    d, h = map(int, input().split())
    ds.append(d)
    hs.append(h)

res = 0
if ds[0] != 1:
    res = max(res, hs[0] + ds[0] - 1)

if ds[m - 1] != n:
    res = max(res, hs[m - 1] + n - ds[m - 1])

for i in range(m):
    res = max(res, hs[i])

for i in range(m - 1):
    d = ds[i + 1] - ds[i]
    ok = False
    for j in range(d + 1):
        mx = hs[i] + j
        left = d - j
        if hs[i + 1] >= mx - left and hs[i + 1] <= mx + left:
            ok = True
            res = max(res, mx)

    if not ok:
        print("IMPOSSIBLE")
        exit(0)

print(res)

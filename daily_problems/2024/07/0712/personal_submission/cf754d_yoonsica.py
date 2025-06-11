import sys
from heapq import heappush, heappop

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
# ---------------------------------------分割线---------------------------------------------------------
n, k = RII()
a = []
for _ in range(n):
    l, r = RII()
    a.append((l, r))

h = []
ans_l, ans_r = 0, -1
for i in sorted(range(n), key=lambda x: a[x]):
    l, r = a[i]
    heappush(h, r)
    if len(h) > k:
        heappop(h)  # 淘汰右端点最小的
    if len(h) == k:
        if h[0] - l > ans_r - ans_l:
            ans_l, ans_r = l, h[0]
print(ans_r - ans_l + 1)
ans = []
if ans_r - ans_l + 1 > 0:
    for i, (l, r) in enumerate(a, 1):
        if l <= ans_l <= ans_r <= r:
            ans.append(str(i))
            if len(ans) == k:
                break
    print(' '.join(ans))
else:
    print(' '.join(str(i) for i in range(1, k + 1)))

import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# Find the leftmost point which doesn's satisfy the condition. Which segments should you delete?
# 那肯定删除右端点最远的，用最大堆来实现

N = 2 * 10 ** 5 + 1
n, k = MII()
rs, seg_l, seg_r = [], [[] for _ in range(N)], [[] for _ in range(N + 1)]
for i in range(n):
    l, r = MII()
    rs.append(r)
    seg_l[l].append(i)
    seg_r[r + 1].append(i)

hpq = [] # 负数实现最大堆
used = [0] * n
cur = 0 # 当前点的覆盖次数

ans = []
for i in range(N): # 枚举所有点
    # 把左端点加上，把右端点去掉
    for idx in seg_l[i]:
        cur += 1
        used[idx] = 1
        heappush(hpq, (-rs[idx], idx))
    
    for idx in seg_r[i]:
        if used[idx]: # 还没有被删除
            cur -= 1
            used[idx] = 0
    
    while cur > k:
        idx = heappop(hpq)[1]
        if used[idx]:
            cur -= 1
            used[idx] = 0
            ans.append(idx + 1)

print(len(ans))
print(*ans)
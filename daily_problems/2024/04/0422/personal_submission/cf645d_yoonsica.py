# 快读板子
import sys
from collections import defaultdict, deque
RII = lambda: map(int, sys.stdin.readline().strip().split())


n,m = RII()
# 二分答案
edges = []
for _ in range(m):
    u, v = RII()
    edges.append((u - 1,v - 1))


def check(k):
    deg = [0]*n
    g = defaultdict(list)
    for u, v in edges[:k]:
        g[u].append(v)
        deg[v] += 1
    q = deque([i for i,x in enumerate(deg) if x == 0])
    cnt = 0
    while q:
        if len(q) > 1:
            # 拓扑序不唯一
            return False
        u = q.popleft()
        cnt += 1
        if cnt == n:
            return True
        for v in g[u]:
            deg[v] -= 1
            if not deg[v]:
                q.append(v)
    return False


def solve():
    l,r = 0, m + 1
    while l + 1 < r:
        mid = (l + r) // 2
        if check(mid):
            r = mid
        else:
            l = mid
    if check(r):
        return r
    return -1

print(solve())

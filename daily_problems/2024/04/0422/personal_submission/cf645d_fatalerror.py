"""
拓扑排序，拓扑序唯一要求拓扑排序中队列元素个数不能多于1。二分查找最少需要的边数。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

def solve():
    n, m = lii()
    edges = []
    for _ in range(m):
        u, v = lii()
        u -= 1; v -= 1
        edges.append((u, v))

    def toposort(g):
        indeg = [0] * n
        for children in g:
            for v in children:
                indeg[v] += 1

        q = [u for u in range(n) if indeg[u] == 0]
        ans = []
        while q:
            if len(q) != 1:
                return False
            u = q.pop()
            ans.append(u)
            for v in g[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        return True

    lo, hi = 1, m+1
    while lo < hi:
        mid = (lo + hi) // 2
        g = [[] for _ in range(n)]
        for i in range(mid):
            u, v = edges[i]
            g[u].append(v)
        if toposort(g):
            hi = mid
        else:
            lo = mid + 1

    return lo if lo <= m else -1

print(solve())
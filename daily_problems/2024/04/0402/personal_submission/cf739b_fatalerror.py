# `@bootstrap` is required for recursion.
# For details see: https://codeforces.com/contest/739/submission/254728118

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

from bisect import bisect_left

def solve():
    n = ii()
    arr = [0] + lii()
    g = [[] for _ in range(n+1)]
    parents = [0] * (n+1)
    for v in range(2, n+1):
        u, w = lii()
        g[u].append((v, w))
        parents[v] = u

    diff = [0] * (n+1)
    path = [1]
    dis = [0]
    def dfs(u):
        for v, w in g[u]:
            path.append(v)
            d = dis[-1] + w
            dis.append(d)
            idx = bisect_left(dis, d-arr[v])
            diff[parents[path[idx]]] -= 1
            diff[parents[v]] += 1
            dfs(v)
            path.pop()
            dis.pop()
    dfs(1)

    def calc(u):
        for v, _ in g[u]:
            calc(v)
            diff[u] += diff[v]
    calc(1)

    return diff[1:]

print(*solve())
"""
n 数据范围更大的情况可以参考 Tutorial。
个人提交：https://codeforces.com/contest/1286/submission/265014937
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

sys.setrecursionlimit(2010)

n = ii()
g = [[] for _ in range(n+1)]
cnt = [0] * (n+1)
for u in range(1, n+1):
    pa, c = mii()
    g[pa].append(u)
    cnt[u] = c

valid = True

def dfs(u):
    global valid
    if not valid:
        return []
    order = []
    for v in g[u]:
        order.extend(dfs(v))
    if cnt[u] > len(order):
        valid = False
        return []
    else:
        order.insert(cnt[u], u)
        return order

order = dfs(0)
if not valid:
    print('NO')
else:
    ans = [0] * (n+1)
    for w, u in enumerate(order):
        ans[u] = w
    print('YES')
    print(*ans[1:])

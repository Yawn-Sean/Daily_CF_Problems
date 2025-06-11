import sys
from math import inf
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1320/B
目标从p1走到pk，导航会选择最短路，实际车主走的路线是p,求导航重新规划路线的最多和最少次数

可以求t到每个点的最短路，然后判断每个dis[p[i + 1] + 1 == dis[p[i]],如果不等，肯定要切换路线，
否则，如果p[i]的邻居有多个都满足，则可能切换路线
'''
n, m = RII()
g = [[] for _ in range(n + 1)]
rev_g = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = RII()
    g[u].append(v)
    rev_g[v].append(u) # 建反图

k = RI()
p = [0] + RILIST()

dis = [inf] * (n + 1)
dis[p[-1]] = 0

cur = [p[-1]]
while cur:
    nxt = []
    for u in cur:
        for v in rev_g[u]:
            if dis[v] > dis[u] + 1:
                dis[v] = dis[u] + 1
                nxt.append(v)
    cur = nxt

ans = [0, 0]
for i in range(1, k):
    if dis[p[i + 1]] + 1 != dis[p[i]]:
        ans[0] += 1
        ans[1] += 1
    else:
        cnt = 0
        for v in g[p[i]]:
            if dis[v] + 1 == dis[p[i]]:
                cnt += 1
                if cnt > 1:
                    ans[1] += 1
                    break
print(*ans)
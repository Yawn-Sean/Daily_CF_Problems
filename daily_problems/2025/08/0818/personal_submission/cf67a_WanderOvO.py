"""
是否可以直接差分约束干了？似乎是可以的
a[i] > a[i + 1]，则 a[i] >= a[i + 1] + 1
连接 (i + 1, i, 1) 这条边
a[i] < a[i + 1]，连接 (i, i + 1, 1) 这条边
a[i] >= 1, 不妨连接 (n, i, 1) 这条边，强制一下
从 n 出发，跑最长路，其实就是所有边权取相反数，求最短路
"""

n = int(input())
s = input()

es = []
for i in range(len(s)):
    if s[i] == '=':
        es.append((i, i + 1, 0))
        es.append((i + 1, i, 0))
    elif s[i] == 'L':
        es.append((i + 1, i, -1))
    else:
        es.append((i, i + 1, -1))
for i in range(n):
    es.append((n, i, -1))

INF = int(1e9)
d = [INF for _ in range(n + 1)]
d[n] = 0

for rd in range(n):
    for i in range(len(es)):
        u, v, w = es[i]
        d[v] = min(d[v], d[u] + w)
for i in range(n):
    print(-d[i], end=' ')

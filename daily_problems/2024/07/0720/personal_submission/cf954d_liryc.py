'''
https://codeforces.com/contest/954/submission/271485305
954D
2024/7/20 Y1
1600
BFS, then just enumerate all pairs to find answers
'''
from collections import deque

n, m, s, t = map(int, input().split())
g = [[] for _ in range(n + 1)]
roads = set()
for _ in range(m):
    u, v = map(int, input().split())
    if u > v: 
        u, v = v, u
    roads.add((u, v))
    g[u].append(v)
    g[v].append(u)

def bfsAll(src):
    global n, g
    a = [-1] * (n + 1)
    a[src] = 0
    qu = deque()
    qu.append(src)
    while qu:
        s = qu.popleft()
        for t in g[s]:
            if a[t] < 0:
                a[t] = a[s] + 1
                qu.append(t)
    return a
    
sd = bfsAll(s)
td = bfsAll(t)
mindist = sd[t]
ans = 0
for i in range(1, n):
    for j in range(i + 1, n + 1):
        if (i, j) not in roads and sd[i] + 1 + td[j] >= mindist and sd[j] + 1 + td[i] >= mindist:
            ans += 1
print(ans)
import sys
input = lambda: sys.stdin.readline().rstrip()
mii = lambda: map(int, input().split())

n, nq = mii()
n += 1
parent = list(range(n))

def find(x):
    t = x
    while parent[x] != x:
        x = parent[x]
    while t != x:
        t, parent[t] = parent[t], x
    return x

def union(x, y):
    rx, ry = find(x), find(y)
    parent[rx] = ry

out = [False] * n
g = [[] for _ in range(n)]
packets = []
queries = []
ansidx = 0
for _ in range(nq):
    tp, *q = mii()
    if tp == 1:
        u, v = q
        union(u, v)
        out[u] = True
        g[v].append(u)
    elif tp == 2:
        u = q[0]
        packets.append((u, find(u)))
        queries.append([])
    else:
        u, x = q
        x -= 1
        queries[x].append((u, ansidx))
        ansidx += 1

dfnin = [0] * n
dfnout = [0] * n
timestamp = 0
stk = [u for u in range(n) if not out[u]]
while stk:
    u = stk.pop()
    if u >= 0:
        dfnin[u] = timestamp
        stk.append(~u)
        stk.extend(g[u])
    else:
        dfnout[~u] = timestamp
    timestamp += 1

def is_ancestor(u, v):
    return dfnin[v] <= dfnin[u] <= dfnout[v]

ans = [False] * ansidx
for (u, rt), q in zip(packets, queries):
    for v, ansidx in q:
        ans[ansidx] = is_ancestor(u, v) and is_ancestor(v, rt)

for st in ans:
    print('YES' if st else 'NO')
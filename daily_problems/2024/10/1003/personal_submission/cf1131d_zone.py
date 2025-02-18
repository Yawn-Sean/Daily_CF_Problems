"""
problem url   : https://codeforces.com/problemset/problem/1131/D
submission url: https://codeforces.com/contest/1131/submission/284112077
"""

n, m = MII() 
a = [I() for _ in range(n)]

un_find = UnionFind(n + m)
for i in range(n):
    for j in range(n, n + m):
        if a[i][j - n] == '=':
            un_find.merge(i, j)

adj = [[] for _ in range(n + m)]
indeg = [0] * (n + m)
for i in range(n):
    for j in range(n, n + m):
        u = un_find.find(i)
        v = un_find.find(j)

        if a[i][j - n] == '>':
            adj[v].append(u)
            indeg[u] += 1
        elif a[i][j - n] == '<':
            adj[u].append(v)
            indeg[v] += 1 

stk = [i for i in range(n + m) if indeg[i] == 0]
ans = [int(x == 0) for x in indeg]

cnt = 0

while stk: 
    u = stk.pop() 
    cnt += 1 
    for v in adj[u]: 
        ans[v] = max(ans[v], ans[u] + 1)
        indeg[v] -= 1 
        if indeg[v] == 0: 
            stk.append(v)

if cnt < n + m: 
    print("No")
else:
    print("Yes")
    print(' '.join(str(ans[un_find.find(i)]) for i in range(n)))
    print(' '.join(str(ans[un_find.find(i)]) for i in range(n, n + m)))

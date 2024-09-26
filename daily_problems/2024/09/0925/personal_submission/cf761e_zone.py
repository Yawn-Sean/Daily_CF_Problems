"""
problem url   : https://codeforces.com/problemset/problem/761/E
submission url: https://codeforces.com/contest/761/submission/282874126
"""

n = II()
adj = [[] for _ in range(n)]
for i in range(n - 1):
    u, v = GMI() 
    adj[u].append(v)
    adj[v].append(u)

dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

ans = [None] * n 
ans[0] = (0, 0)
stk = [(0, -1, 1 << 30)]
while stk: 
    u, dr, length = stk.pop()
    cur = 0
    if len(adj[u]) > 4: 
        print("NO")
        exit()
    for v in adj[u]: 
        if ans[v] is None:
            if cur == dr: 
                cur += 1 
            dx, dy = dirs[cur % 4]
            x, y = ans[u][0] + dx * length, ans[u][1] + dy * length
            ans[v] = (x, y)
            stk.append((v, cur ^ 2, length // 2))
            cur = (cur + 1) % 4
print("YES")
print('\n'.join([f"{i} {j}" for i, j in ans]))

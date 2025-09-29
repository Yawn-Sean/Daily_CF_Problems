n, m, k = il()
adj = [set() for _ in range(n)]
for i in range(m):
    u,v = il()
    u -= 1
    v -= 1
    adj[u].add(v)
    adj[v].add(u)
ans = [0] * n
x = 0
for i in range(n):
    if not ans[i]:
        x += 1
        ans[i] = x
        for j in range(n):
            if not ans[j] and (j not in adj[i]):
                ans[j] = x
if x > k:
    exit(print(-1))
for i in range(n):
    for j in range(i + 1, n):
        if (ans[i] == ans[j]) == (j in adj[i]):
            exit(print(-1))
print(*ans)

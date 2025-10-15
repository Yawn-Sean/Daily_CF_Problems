n, x, y = map(int, input().split())
x -= 1
y -= 1
g = [[]for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)
def dfs(x, y):    
    q = [x]
    st = [False] * n
    st[x] = True
    while q:
        u = q.pop()
        for v in g[u]:
            if v != y and not st[v]:
                q.append(v)
                st[v] = True
    return sum(st)
print(n *(n - 1) - (n - dfs(x, y))* (n - dfs(y, x)))

def bfs(start):
    q = [start]
    visited = [0] * (n + 1)
    visited[start] = 1
    children = [[] for _ in range(n + 1)]
    
    for node in q:
        for neighbor in graph[node]:
            if not visited[neighbor]:
                q.append(neighbor)
                visited[neighbor] = 1
                children[node].append(neighbor)
    
    return q, children

n = II()
weights = LII()
graph = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    u, v = MII()
    graph[u].append(v)
    graph[v].append(u)

order, children = bfs(1)

result = -inf
dp = [0] * (n + 1)
a = [0] + weights

for node in reversed(order):
    for child in children[node]:
        a[node] += a[child]
    dp[node] = a[node]
    csums = sorted([dp[child] for child in children[node]], reverse=True)
    
    if len(csums) >= 2:
        result = max(result, csums[0] + csums[1])
    
    if csums:
        dp[node] = max(dp[node], csums[0])

if result == -inf:
    print("Impossible")
else:
    print(result)

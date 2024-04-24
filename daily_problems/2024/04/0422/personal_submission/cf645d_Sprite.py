n, m = map(int, input().split())
edges = []
for _ in range(m):
    edges.append(list(map(lambda x: int(x)-1, input().split())))

def check(x):
    connect = [[] for _ in range(n)]
    ind = [0] * n
    for i in range(x):
        u, v = edges[i]
        connect[u].append(v)
        ind[v] += 1
    
    q = []
    for i in range(n):
        if ind[i] == 0:
            q.append(i)
    arrive = []
    while q:
        if len(q) > 1:
            return False
        now = q.pop()
        arrive.append(now)
        for i in connect[now]:
            ind[i] -= 1
            if ind[i] == 0:
                q.append(i)
    if len(arrive) == n:
        return True
    else:
        return False

l, r = 0, m
while l <= r:
    mid = (l + r) // 2
    if check(mid):
        r = mid - 1
    else:
        l = mid + 1
print(l if l <= m else -1)

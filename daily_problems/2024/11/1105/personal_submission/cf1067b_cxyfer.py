from collections import deque

n, k = map(int, input().split())
g = [[] for _ in range(n + 1)]
deg = [0] * (n + 1)
for _ in range(n - 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
    deg[u] += 1
    deg[v] += 1

dist1 = [-1] * (n + 1) # 距離葉子節點的距離
q = deque()
for u in range(1, n + 1):
    if deg[u] == 1:
        dist1[u] = 0
        q.append(u)

while q:
    u = q.popleft()
    for v in g[u]:
        if dist1[v] == -1:
            dist1[v] = dist1[u] + 1
            q.append(v)

mx = max(dist1)
rt = dist1.index(mx) # 根節點
dist2 = [-1] * (n + 1) # 距離根節點的距離
q = deque([rt])
dist2[rt] = 0
while q:
    u = q.popleft()
    for v in g[u]:
        if dist2[v] == -1:
            dist2[v] = dist2[u] + 1
            q.append(v)

# 根節點的距離必須為 k，且根節點的度數必須 >=3 ，且只能有一個節點和葉節點的距離為 k
if mx != k or deg[rt] < 3 or len([u for u in range(1, n + 1) if dist1[u] == mx]) != 1:
    exit(print("No"))

for u in range(1, n + 1):
    # 葉節點到根節點的距離必須為 k
    if deg[u] == 1:
        if dist2[u] != k:
            exit(print("No"))
    # 非葉且非根節點的度數必須 > 3
    elif u != rt and deg[u] <= 3:
        exit(print("No"))
print("Yes")

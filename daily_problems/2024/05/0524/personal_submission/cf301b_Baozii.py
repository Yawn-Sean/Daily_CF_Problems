from math import inf

def dis(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

n, d = map(int, input().split())
arr = list(map(int, input().split()))
arr.insert(0, 0)
arr.append(0)
points = [list(map(int, input().split())) for _ in range(n)]
graph = [[] for _ in range(n)]

for i in range(n):
    for j in range(i + 1, n):
        m_dis = dis(points[i][0], points[i][1], points[j][0], points[j][1]) * d
        graph[i].append([j, m_dis])
        graph[j].append([i, m_dis])
        
# Dijkstra
dist = [inf] * n
dist[0] = 0
vis = [False] * n
for _ in range(n - 1):
    mi = inf
    x = -1
    for i in range(n):
        if not vis[i] and dist[i] < mi:
            x = i
            mi = dist[x]
    for y, d in graph[x]:
        dist[y] = min(dist[y], dist[x] + d - arr[y])
    vis[x] = True
print(dist[-1])

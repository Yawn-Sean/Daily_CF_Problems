def dijkstra(n, k, edges):
    INF = float('inf')
    dis = [INF] * (n + 1)
    dis[1] = 0
    vis = [False] * (n + 1)
    
    graph = [[] for _ in range(n + 1)]
    for u, v, w, id_ in edges:
        graph[u].append((v, w, id_))
        graph[v].append((u, w, id_))

    pq = [(0, 1, 0)]
    heapq.heapify(pq)
    
    results = []
    
    while pq:
        _, x, edge_id = heapq.heappop(pq)
        
        if vis[x]:
            continue
        
        vis[x] = True
        if edge_id > 0 and k > 0:
            k -= 1
            results.append(edge_id)
        
        if k == 0:
            break
        
        for y, w, id_ in graph[x]:
            if dis[y] > dis[x] + w:
                dis[y] = dis[x] + w
                heapq.heappush(pq, (dis[y], y, id_))
    
    return results

def main():
    data = input().split()
    index = 0
    n = int(data[index])
    index += 1
    m = int(data[index])
    index += 1
    k = int(data[index])
    index += 1
    
    k = min(k, n - 1)
    
    edges = []
    for i in range(m):
        u = int(data[index])
        index += 1
        v = int(data[index])
        index += 1
        w = int(data[index])
        index += 1
        edges.append((u, v, w, i + 1))
    
    results = dijkstra(n, k, edges)
    results.sort()
    print(' '.join(map(str, results)))

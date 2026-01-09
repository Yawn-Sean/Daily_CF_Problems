import heapq

def sol():
    n, m = map(int, input().split())
    g1 = [[] for _ in range(n + 1)]
    g2 = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        g1[a].append((b, c))
        g2[b].append((a, c))

    def uuz(e):
        dist = [0x3f3f3f3f] * (n + 1)
        pq = [(0, 1)]
        dist[1] = 0

        while len(pq):
            dist_x, x = heapq.heappop(pq)
            for y, w in e[x]:
                if dist[y] > max(dist[x], w):
                    dist[y] = max(dist[x], w)
                    heapq.heappush(pq, (dist[y], y))

        return dist
    
    dist1 = uuz(g1)
    dist2 = uuz(g2)

    for i in range(1, n + 1):
        if dist1[i] < dist2[i]:
            return False
    return True


print('YES' if sol() else 'NO')

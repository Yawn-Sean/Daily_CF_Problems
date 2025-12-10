import heapq
import sys

input = lambda: sys.stdin.readline().rstrip()

def soviet():
    n, m, k = map(int, input().split())
    e = [[] for _ in range(n + k + 1)]

    for _ in range(m):
        u, v, c = map(int, input().split())
        e[u].append(c << 20 | v)
        e[v].append(c << 20 | u)

    for i in range(1, n + 1):
        t = int(input())
        for _ in range(t):
            u, c = map(int, input().split())
            e[i].append( (c << 20) | (u + n))
            e[u + n].append(i)

    def uuz() -> int :
        dist = [1 << 60] * (n + k + 1)
        vis = [False] * (n + k + 1)
        pq = [1]
        dist[1] = 0
        mask = (1 << 20) - 1
        while pq:
            x = heapq.heappop(pq) & mask
            if x == n:
                return dist[x]
            if vis[x]:
                continue
            else:
                vis[x] = True
            for edge in e[x]:
                y, w = edge & mask, edge >> 20
                if dist[y] > dist[x] + w:
                    dist[y] = dist[x] + w
                    heapq.heappush(pq, (dist[y] << 20) | y)
        return dist[n]

    print(uuz())

soviet()

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()

def soviet():
    n, m, s, t = map(int, input().split())
    s -= 1
    t -= 1
    mod = 10 ** 9 + 7

    edges = []
    head = [-1] * n
    nxt = [0] * (2 * m)

    def add_edge(u, v):
        nonlocal edges
        edges.append(v)
        nxt[len(edges) - 1] = head[u]
        head[u] = len(edges) - 1

    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        add_edge(u, v)
        add_edge(v, u)

    dist = [-1] * n
    dist[s] = 0
    max_dist = 0

    q = deque([s])

    dist_layers = []

    while q:
        u = q.popleft()
        cur_dist = dist[u]

        if cur_dist >= len(dist_layers):
            dist_layers.append([])
        dist_layers[cur_dist].append(u)
        max_dist = max(max_dist, cur_dist)

        e = head[u]
        while e != -1:
            v = edges[e]
            if dist[v] == -1:
                dist[v] = cur_dist + 1
                q.append(v)
            e = nxt[e]

    dp0 = [0] * n
    dp1 = [0] * n
    dp0[s] = 1

    for d in range(max_dist + 1):
        for u in dist_layers[d]:
            e = head[u]
            while e != -1:
                v = edges[e]
                if dist[v] == dist[u]:
                    dp1[v] = (dp1[v] + dp0[u]) % mod
                e = nxt[e]

        for u in dist_layers[d]:
            e = head[u]
            while e != -1:
                v = edges[e]
                if dist[v] == dist[u] + 1:
                    dp0[v] = (dp0[v] + dp0[u]) % mod
                    dp1[v] = (dp1[v] + dp1[u]) % mod
                e = nxt[e]

    print(dp1[t] % mod)

if __name__ == "__main__":
    soviet()

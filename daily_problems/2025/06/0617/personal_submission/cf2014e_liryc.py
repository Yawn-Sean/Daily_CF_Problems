'''
https://codeforces.com/problemset/submission/2014/324725497
'''
# dijkstra
def solve(n: int, m: int, h: int, a: list[int], edges: list[list[int]]) -> int:
    hs = set(x - 1 for x in a)
    g = [[] for _ in range(n)]
    for u, v, w in edges:
        g[u - 1].append([v - 1, w])
        g[v - 1].append([u - 1, w])

    def dijkstra(start):
        nonlocal n, hs, g
        vis, hvis = [-1] * n, [-1] * n
        hp = [] 
        if start in hs: 
            hvis[start] = 0
            hp.append((0, ~start))
        else:
            vis[start] = 0
            hp = [(0, start)]
        while hp:
            t, u = heappop(hp)
            t0 = hvis[~u] if u < 0 else vis[u]
            if t > t0:
                continue
            horse = False
            if u < 0:
                u = ~u
                horse = True
            for v, w in g[u]:
                s = t + w // 2 if horse else t + w
                if horse or v in hs:
                    if hvis[v] < 0 or s < hvis[v]:
                        hvis[v] = s
                        heappush(hp, (s, ~v))
                else:
                    if vis[v] < 0 or s < vis[v]:
                        vis[v] = s
                        heappush(hp, (s, v))
        for i in range(n):
            if hvis[i] >= 0 and (vis[i] < 0 or hvis[i] < vis[i]):
                vis[i] = hvis[i]
        return vis
    
    vis0 = dijkstra(0)
    if vis0[n - 1] < 0:
        return -1
    vis1 = dijkstra(n - 1)
    return min(max(vis0[i], vis1[i]) for i in range(n) if vis0[i] >= 0 and vis1[i] >= 0)
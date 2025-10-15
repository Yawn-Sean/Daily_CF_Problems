'''
https://codeforces.com/problemset/submission/1915/320307197
'''
# shortest path
def solve(n: int, m: int, edges: list[list[int]], sa: list[int]) -> int:
    vis = [[-1] * 1001 for _ in range(1001)]
    ug = [[] for _ in range(n)]
    for u, v, w in edges:
        ug[u - 1].append((v - 1, w))
        ug[v - 1].append((u - 1, w))
    vis[0][sa[0]] = 0
    hp = [(0, sa[0], 0)]
    while hp:
        t, s, u = heappop(hp)
        if u == n - 1:
            return t
        elif vis[u][s] < t:
            continue
        for v, w in ug[u]:
            sr = pmin(s, sa[v])
            tr = t + s * w
            if vis[v][sr] < 0 or tr < vis[v][sr]:
                vis[v][sr] = tr
                heappush(hp, (tr, sr, v))

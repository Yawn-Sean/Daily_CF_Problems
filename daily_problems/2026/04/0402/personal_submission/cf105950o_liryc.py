'''
https://codeforces.com/gym/105950/submission/369332297
'''
# dijkstra
def solve(n: int, m: int, g: list[list[int]], d: int, da: list[int], ea: list[int]):
    vis = [-1] * n
    vis[0] = 0
    hp = [0]
    while hp:
        u, mw = dec(heappop(hp))
        if vis[u] == mw:
            for e in g[u]:
                v, w = dec(e)
                if pmin(vis[v], pmax(w, mw)) != vis[v]:
                    vis[v] = pmax(w, mw)
                    heappush(hp, enc(v, pmax(w, mw)))
    ea.sort()
    ans, ei = 0, 0
    for u in sorted(da, key=lambda v: vis[v]):
        if vis[u] == -1:
            continue
        while ei < d and ea[ei] < vis[u]:
            ei += 1
        if ei == d:
            break
        if vis[u] >= 0 and ea[ei] >= vis[u]:
            ei += 1
            ans += 1

    return ans

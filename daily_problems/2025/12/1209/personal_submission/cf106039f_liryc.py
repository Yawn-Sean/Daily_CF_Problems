'''
https://codeforces.com/gym/106039/submission/352679995
'''
# dijkstra
def init():
    n, m, k = map(int, input().split())
    g = [[] for _ in range(n + k)]
    for _ in range(m):
        u, v, c = map(int, input().split())
        u, v = u - 1, v - 1
        g[u].append(c << 20 | v)
        g[v].append(c << 20 | u)
    for u in range(n):
        t = int(input())
        for _ in range(t):
            x, c = map(int, input().split())
            x += n - 1
            g[u].append(c << 20 | x)
            g[x].append(u)    
    return n, m, k, g

def solve(n: int, m: int, k: int, g: list[list[int]]) -> int:
    dist = [-1] * (n + k)
    dist[0] = 0
    hp = [0]
    mg = (1 << 20) - 1
    while hp:
        ec = heappop(hp)
        u, c = ec & mg, ec >> 20
        if c > dist[u]:
            continue
        if u == n - 1:
            return c
        for e in g[u]:
            v, d = e & mg, e >> 20
            t = c + d
            if dist[v] < 0 or dist[v] > t:
                dist[v] = t
                heappush(hp, t << 20 | v)
    return -1 

'''
https://codeforces.com/gym/105811/submission/356971716
'''
def init():
    n, m = map(int, input().split())
    tg, rg = [[] for _ in range(n)], [[] for _ in range(n)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        a, b = a - 1, b - 1
        tg[a].append(c << 18 | b)
        rg[b].append(c << 18 | a)
    return n, m, tg, rg

def solve(n: int, m: int, tg: list, rg: list) -> bool:
    dt, df = [2e9] * n, [2e9] * n

    def dijkstra(g: list, d: list):
        nonlocal n
        msk = (1 << 18) - 1
        hp = [0]
        d[0] = 0
        while hp:
            s, u = divmod(heappop(hp), n)
            if d[u] == s:
                for enc in g[u]:
                    nd, v = enc >> 18, enc & msk
                    nd = pmax(s, nd)
                    if nd < d[v]:
                        d[v] = nd
                        heappush(hp, nd * n + v)
    dijkstra(tg, dt)
    dijkstra(rg, df)
    for i in range(n):
        if df[i] > dt[i]:
            return False
    return True

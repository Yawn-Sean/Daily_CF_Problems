'''
20260305 Y1 1700
'''
def solve(n: int, m: int, a: list[int], tg: list[list[int]]) -> bool: 
    INF = (1 << 30) - 1 << 1
    tg = [[] for _ in range(n)]
    pq = [a[i] * n + i for i in range(n)]
    while pq:
        e = heappop(pq)
        d, u = e >> 18, e & (1 << 18) - 1
        if a[u] == d:
            for e in tg[u]:
                nd, v = e >> 18, e & (1 << 18) - 1
                if nd + d < a[v]:
                    a[v] = nd + d
                    heappush(pq, a[v] << 18 | v)
    dis = [INF] * n
    dis[0] = 0
    pq = [0]
    while pq:
        e = heappop(pq)
        d, u = e >> 18, e & (1 << 18) - 1
        if dis[u] == d:
            for e in tg[u]:
                nd, v = e >> 18, e & (1 << 18) - 1
                if nd + d < dis[v] and nd + d <= a[v]:
                    dis[v] = nd + d
                    heappush(pq, dis[v] << 18 | v)
    return dis[n - 1] < INF


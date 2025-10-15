# Submission link: https://codeforces.com/contest/141/submission/336879813
def main():
    n, l = MII()
    rnd = random.getrandbits(30)

    us = []
    vs = []
    ws = []
    ids = []

    for i in range(1, n + 1):
        x, d, t, p = MII()
        if x >= p:
            x += rnd
            us.append(x - p)
            vs.append(x + d)
            ws.append(p + t)
            ids.append(i)

    positions = [rnd, rnd + l]
    positions.extend(us)
    positions.extend(vs)

    positions = sorted(set(positions))

    N = len(positions)
    path = [[] for _ in range(N)]

    def f(d, v):
        return d * N + v

    INF = 10 ** 9 + 5

    def e(idx, d, v):
        return (idx * INF + d) * N + v

    for i in range(1, N):
        d = positions[i] - positions[i - 1]
        path[i].append(e(0, d, i - 1))
        path[i - 1].append(e(0, d, i))

    M = len(us)

    for i in range(M):
        u = us[i]
        v = vs[i]
        w = ws[i]
        
        u_id = bisect.bisect_left(positions, u)
        v_id = bisect.bisect_left(positions, v)
        path[u_id].append(e(ids[i], w, v_id))

    inf = 10 ** 9 * 2

    dis = [inf] * N
    pre = [-1] * N

    pq = [f(0, 0)]
    dis[0] = 0

    while pq:
        d, u = divmod(heappop(pq), N)
        
        if dis[u] == d:
            for msk in path[u]:
                msk, v = divmod(msk, N)
                i, nd = divmod(msk, INF)
                
                if d + nd < dis[v]:
                    dis[v] = d + nd
                    pre[v] = f(i, u)
                    heappush(pq, f(dis[v], v))

    for i in range(N):
        if positions[i] == rnd + l:
            print(dis[i])
            
            ans = []
            cur = i
            while cur:
                msk = pre[cur]
                idx, cur = divmod(msk, N)
                if idx > 0: ans.append(idx)
            
            ans.reverse()
            print(len(ans))
            if len(ans): print(' '.join(map(str, ans)))
            break
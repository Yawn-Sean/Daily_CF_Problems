# Submission link: https://codeforces.com/contest/1076/submission/277242827
def main():
    n, m, k = MII()

    us = []
    vs = []
    ws = []

    path = [[] for _ in range(n)]

    for i in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        path[u].append(i)
        path[v].append(i)

    dis = [10 ** 15] * n
    dis[0] = 0

    parent = [-1] * n
    hpq = [0]

    while hpq:
        d, u = divmod(heappop(hpq), n)
        if dis[u] == d:
            for i in path[u]:
                v = us[i] ^ vs[i] ^ u
                if dis[v] > dis[u] + ws[i]:
                    dis[v] = dis[u] + ws[i]
                    parent[v] = i
                    heappush(hpq, dis[v] * n + v)

    st_range = sorted(range(1, n), key=lambda x: dis[x])
    ans = min(k, n - 1)
    print(ans)
    print(' '.join(str(parent[st_range[i]] + 1) for i in range(ans)))
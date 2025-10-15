# Submission link: https://codeforces.com/contest/101/submission/330643139
def main():
    n = II()
    path = [[] for _ in range(n)]

    us = []
    vs = []
    ws = []

    for i in range(n - 1):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        path[u].append(i)
        path[v].append(i)

    parent = [-1] * n
    que = [0]

    for u in que:
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            if parent[u] != v:
                parent[v] = u
                que.append(v)

    sz = [1] * n
    szt = [0] * n
    dp = [0] * n
    weights = [0] * n

    def cmp(x, y):
        v1 = weights[x] * sz[y]
        v2 = weights[y] * sz[x]
        
        if v1 < v2: return -1
        if v1 > v2: return 1
        return 0

    for u in reversed(que):
        sons = []
        
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            w = ws[eid]
            
            if parent[v] == u:
                sons.append(v)
                weights[v] = w + szt[v]
                sz[u] += sz[v]
                szt[u] += w + szt[v]
                dp[u] += dp[v] + sz[v] * w
        
        sons.sort(key=cmp_to_key(cmp))
        
        total_sz = sz[u] - 1
        for v in sons:
            total_sz -= sz[v]
            dp[u] += weights[v] * total_sz * 2

    print(dp[0] / (n - 1))
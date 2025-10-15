# Submission link: https://codeforces.com/contest/802/submission/328596514
def main():
    n = II()
    mod = 10 ** 9 + 7
    path = [[] for _ in range(n)]

    us = []
    vs = []
    cs = []

    for i in range(n - 1):
        u, v, c = MII()
        path[u].append(i)
        path[v].append(i)
        
        us.append(u)
        vs.append(v)
        cs.append(c)

    parent = [-1] * n

    que = [0]
    for u in que:
        for eid in path[u]:
            if parent[u] != eid:
                v = us[eid] + vs[eid] - u
                parent[v] = eid
                que.append(v)

    ks = [0] * n
    bs = [0] * n

    for u in reversed(que):
        if len(path[u]) == 1 and u > 0: continue
        
        sumk = 0
        sumb = 0
        sumc = 0
        
        for eid in path[u]:
            v = us[eid] + vs[eid] - u
            sumc += cs[eid]
            if parent[v] == eid:
                sumk += ks[v]
                sumb += bs[v]
        
        rev = pow(len(path[u]) - sumk, -1, mod)
        ks[u] = rev
        bs[u] = (sumb + sumc) * rev % mod

    print(bs[0])
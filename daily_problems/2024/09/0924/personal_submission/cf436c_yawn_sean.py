# Submission link: https://codeforces.com/contest/436/submission/282700350
def main():
    n, m, k, w = MII()

    grids = []

    for _ in range(k):
        grids.append([I() for _ in range(n)])

    us = []
    vs = []
    ws = []

    for i in range(k):
        us.append(i)
        vs.append(k)
        ws.append(n * m)
        
        for j in range(i):
            cnt = 0
            for x in range(n):
                for y in range(m):
                    if grids[i][x][y] != grids[j][x][y]:
                        cnt += 1
            us.append(i)
            vs.append(j)
            ws.append(cnt * w)

    e = len(ws)
    union = UnionFind(k + 1)
    path = [[] for _ in range(k + 1)]

    ans = 0
    for i in sorted(range(e), key=lambda x: ws[x]):
        if union.merge(us[i], vs[i]):
            path[us[i]].append(vs[i])
            path[vs[i]].append(us[i])
            ans += ws[i]

    parent = [-1] * (k + 1)
    stk = [k]

    outs = []
    while stk:
        u = stk.pop()
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                stk.append(v)
                outs.append(f'{v + 1} {parent[v] + 1 if parent[v] != k else 0}')

    print(ans)
    print('\n'.join(outs))
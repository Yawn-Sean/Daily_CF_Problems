# Submission link: https://codeforces.com/contest/466/submission/302682629
def main():
    n, q = MII()

    ts = []
    xs = []
    ys = []

    parent = [0] * (n + 1)
    parent[0] = -1

    for _ in range(q):
        query = LII()
        
        ts.append(query[0])
        xs.append(query[1])
        ys.append(-1 if len(query) < 3 else query[2])
        
        if query[0] == 1:
            parent[query[1]] = query[2]

    path = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        p = parent[i]
        path[i].append(p)
        path[p].append(i)

    ls = [-1] * (n + 1)
    rs = [-1] * (n + 1)

    tmstamp = 0

    stk = [0]

    while stk:
        u = stk.pop()
        if u >= 0:
            ls[u] = tmstamp
            tmstamp += 1
            stk.append(~u)
            
            for v in path[u]:
                if parent[v] == u:
                    stk.append(v)
        else:
            rs[~u] = tmstamp

    dsu = UnionFind(n + 1)
    outs = []

    starts = [0]
    ends = [0]

    for i in range(q):
        if ts[i] == 1:
            dsu.merge(ys[i], xs[i])
        elif ts[i] == 2:
            starts.append(xs[i])
            ends.append(dsu.find(xs[i]))
        else:
            x = starts[ys[i]]
            y = ends[ys[i]]
            
            outs.append('YES' if ls[y] <= ls[xs[i]] <= ls[x] and rs[x] <= rs[xs[i]] <= rs[y] else 'NO')

    print('\n'.join(outs))
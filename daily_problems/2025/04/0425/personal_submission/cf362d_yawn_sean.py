# Submission link: https://codeforces.com/contest/362/submission/317116179
def main():
    n, m, p, q = MII()

    us = []
    vs = []
    ws = []

    for _ in range(m):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)

    components = n
    uf = UnionFind(n)

    for i in range(m):
        components -= uf.merge(us[i], vs[i])

    total = [0] * n
    for i in range(m):
        total[uf.find(us[i])] += ws[i]

    if components < q: print('NO')
    elif components - p > q: print('NO')
    elif p and q == n: print('NO')
    else:
        pq = []
        for i in range(n):
            if uf.find(i) == i:
                pq.append(total[i] * n + i)
        
        heapify(pq)
        
        ops = []
        for _ in range(components - q):
            v1, i1 = divmod(heappop(pq), n)
            v2, i2 = divmod(heappop(pq), n)
            
            ops.append(f'{i1 + 1} {i2 + 1}')
            uf.merge(i1, i2)
            heappush(pq, fmin(2 * (v1 + v2) + 1, 10 ** 9) * n + uf.find(i1))

        resid = p - (components - q)
        if m:
            for _ in range(resid):
                ops.append(f'{us[0] + 1} {vs[0] + 1}')
        
        else:
            for _ in range(resid):
                ops.append(ops[-1])
        
        print('YES')
        print('\n'.join(ops))
def main():
    n, m, k = MII()
    pos = LGMI()
    edges = [tuple(GMI()) for _ in range(k)]

    cnt = [0] * m
    for x in pos:
        cnt[x] += 1

    l, r = -1, 10 ** 9

    inf = 100

    while l <= r:
        mid = (l + r) // 2
        mf = MFGraph(m * 250 + 2)
        src = m * 250
        dst = src + 1
        
        for i in range(m):
            if cnt[i]:
                mf.add_edge(src, i, cnt[i])
        
        for i in range(249):
            for j in range(m):
                mf.add_edge(i * m + j, (i + 1) * m + j, inf)
            for u, v, t in edges:
                if t < mid - 248 + i:
                    mf.add_edge(i * m + u, (i + 1) * m + v, 1)
                    mf.add_edge(i * m + v, (i + 1) * m + u, 1)
        
        mf.add_edge(249 * m, dst, inf)
        
        if mf.flow(src, dst) == n: r = mid - 1
        else: l = mid + 1

    print(l + 1)
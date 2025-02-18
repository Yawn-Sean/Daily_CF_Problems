# Submission link: https://codeforces.com/contest/1320/submission/284988719
def main():
    n, m, p = MII()

    vas = []
    cas = []
    for _ in range(n):
        a, ca = MII()
        vas.append(a)
        cas.append(ca)

    vbs = []
    cbs = []
    for _ in range(m):
        b, cb = MII()
        vbs.append(b)
        cbs.append(cb)

    xs = []
    ys = []
    zs = []
    for _ in range(p):
        x, y, z = MII()
        xs.append(x)
        ys.append(y)
        zs.append(z)

    vals = sorted(set(sorted(vbs)))
    d = {v: i for i, v in enumerate(vals)}

    k = len(vals)
    inf = 10 ** 9
    tmp = [-inf] * k
    for i in range(m):
        tmp[d[vbs[i]]] = fmax(tmp[d[vbs[i]]], -cbs[i])

    seg = LazySegTree(fmax, -inf, add, add, 0, tmp)

    st_range1 = sorted(range(n), key=lambda x: vas[x])
    st_range2 = sorted(range(p), key=lambda x: xs[x])

    pt = 0

    ans = -2 * inf
    for i in st_range1:
        while pt < p and vas[i] > xs[st_range2[pt]]:
            seg.apply(bisect.bisect_right(vals, ys[st_range2[pt]]), k, zs[st_range2[pt]])
            pt += 1
        ans = fmax(ans, seg.all_prod() - cas[i])

    print(ans)
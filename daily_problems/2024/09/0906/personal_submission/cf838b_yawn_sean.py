# Submission link: https://codeforces.com/contest/838/submission/280002743
def main():
    n, q = MII()

    us = []
    vs = []
    ws = []

    tree = [[] for _ in range(n)]
    to_root = [0] * n

    for i in range(2 * (n - 1)):
        u, v, w = MII()
        u -= 1
        v -= 1
        us.append(u)
        vs.append(v)
        ws.append(w)
        if i < n - 1:
            tree[u].append(i)
        else:
            to_root[u] = w

    depth = [0] * n

    ls = [0] * n
    rs = [-1] * n
    order = []

    stk = [0]
    while stk:
        u = stk.pop()
        if u >= 0:
            ls[u] = len(order)
            order.append(u)
            stk.append(~u)
            for i in tree[u]:
                depth[vs[i]] = depth[us[i]] + ws[i]
                stk.append(vs[i])
        else:
            rs[~u] = len(order)

    inf = 10 ** 12

    seg_depth = LazySegTree(lambda x, y: 0, 0, add, add, 0, [depth[x] for x in order])
    seg_to_root = LazySegTree(fmin, inf, add, add, 0, [depth[x] + to_root[x] for x in order])

    outs = []
    for _ in range(q):
        t, x, y = GMI()
        if t:
            if ls[x] <= ls[y] and rs[y] <= rs[x]:
                outs.append(seg_depth.get(ls[y]) - seg_depth.get(ls[x]))
            else:
                outs.append(seg_to_root.prod(ls[x], rs[x]) - seg_depth.get(ls[x]) + seg_depth.get(ls[y]))
        else:
            y += 1
            delta = y - ws[x]
            ws[x] = y
            if x < n - 1:
                seg_depth.apply(ls[vs[x]], rs[vs[x]], delta)
                seg_to_root.apply(ls[vs[x]], rs[vs[x]], delta)
            else:
                seg_to_root.apply(ls[us[x]], ls[us[x]] + 1, delta)

    print('\n'.join(map(str, outs)))
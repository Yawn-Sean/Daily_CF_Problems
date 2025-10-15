# Submission link: https://codeforces.com/contest/1006/submission/324312010
def main():
    n, q = MII()
    parent = [-1] + LGMI()

    path = [[] for _ in range(n)]

    for i in range(1, n):
        path[parent[i]].append(i)

    for i in range(n):
        path[i].reverse()

    stk = [0]
    order = []
    pos = [-1] * n

    while stk:
        u = stk.pop()
        pos[u] = len(order)
        order.append(u)
        
        for v in path[u]:
            stk.append(v)

    sz = [1] * n
    for u in reversed(order):
        if u: sz[parent[u]] += sz[u]

    outs = []
    for _ in range(q):
        u, k = GMI()
        outs.append(order[pos[u] + k] + 1 if k < sz[u] else -1)

    print('\n'.join(map(str, outs)))